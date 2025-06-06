#include "dept.h"
#include "ui_dept.h"


#include <json.hpp>

using json = nlohmann::json;

dept::dept(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dept)
{
    ui->setupUi(this);


    ui->per_combo->addItem("일반");               // 인덱스 0
    ui->per_combo->addItem("관리자");             // 인덱스 1
    ui->per_combo->addItem("슈퍼유저");           // 인덱스 2
    // ui->per_combo->setCurrentIndex(0);
    // 콤보박스가 변경되면 permission 변수를 할당
    connect(ui->per_combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &dept::onPermissionComboBoxChanged);

    // this->req_dept_json_for_first_page();
    connect(ui->reg_dept_btn, &QPushButton::clicked, this, &dept::make_dept);
    connect(ui->update_dept_btn, &QPushButton::clicked,  this, &dept::update_dept);
    connect(ui->tw_dept, &QTableWidget::cellClicked, this, &dept::onTableItemClicked);
    connect(ui->delete_dept_btn, &QPushButton::clicked, this, &dept::delete_dept);

    this->make_req_json_for_deptList();
}

dept::~dept()
{
    delete ui;
}
void dept::delete_dept(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this,
        "삭제 확인",
        "정말 삭제하시겠습니까?",
        QMessageBox::Yes | QMessageBox::No
        );

    if(reply == QMessageBox::Yes){
        //삭제수행!
        performDelete(dept_id);
    }
}
void dept::performDelete(int dept_id){
    //삭제 json 생성
    json j,data;

    j["type"] = "req_dept_delete";

    data["DEPT_ID"] = dept_id;
    j["data"] = data;

    QString jsonString = QString::fromStdString(j.dump(4));
    QString filePath =QString(FILE_PATH)+"/make_dept.json";

    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out <<jsonString;
        file.close();
        qDebug()<<"JSON saved to" <<filePath;

    }else{
        qWarning()<<"Failed to save json to file";

    }

    // 사실 이건 등록을 위한건데 삭제에서도 쓰겠다.
    this->send_json_to_server_for_regist_dept();
    // 이건 삭제후 테이블 위젯을 새로고침하는 내용!
    this->send_json_to_server_to_read_deptList();


}

void dept::update_dept(){
    qDebug()<<"부서 수정버튼 클릭!";
    json j;
    j["type"] = "req_dept_update";
    json data;

    if(!dept_id){
        qDebug()<<"선택한 부서가 없습니당! 테이블 위젯의 아무부서나 클릭!";
    }

    data["DEPT_ID"] = dept_id;
    data["LOGIN_ID"] = ui->dept_user_id->text().toStdString();
    data["LOGIN_PW"] = ui->dept_user_pass_le->text().toStdString();
    data["PERMISSION_LEVEL"] = ui->per_combo->currentIndex();
    data["DEPT_NAME"] = ui->deptName_le->text().toStdString();

    j["data"] = data;

    //json 문자열로 변환
    QString jsonString = QString::fromStdString(j.dump(4));
    QString filePath =QString(FILE_PATH)+"/make_dept.json";
    QFile file(filePath);

    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out <<jsonString;
        file.close();
        qDebug()<<"JSON saved to" <<filePath;

    }else{
        qWarning()<<"Failed to save json to file";

    }

    // 사실 이건 등록을 위한건데 업데이트에서도 쓰겠다.
    this->send_json_to_server_for_regist_dept();
    // 이건 수정후 테이블 위젯을 새로고침하는 내용!
    this->send_json_to_server_to_read_deptList();
}

void dept::make_req_json_for_deptList(){
    json j;
    j["type"] = "req_dept_read";
    //json 문자열로 변환
    QString jsonString = QString::fromStdString(j.dump(4));

    QString filePath =QString(FILE_PATH)+"/read_dept.json";

    QFile file(filePath);

    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out <<jsonString;
        file.close();
        qDebug()<<"JSON saved to" <<filePath;

    }else{
        qWarning()<<"Failed to save json to file";

    }
    this->send_json_to_server_to_read_deptList();

    //새로고침



}

void dept::onTableItemClicked(int row, int column){

    ui->deptName_le->setText(ui->tw_dept->item(row, 3)->text());

    ui->dept_user_id->setText(ui->tw_dept->item(row, 2)->text());
    QString permissionText = ui->tw_dept->item(row, 1)->text();
    int permissionIndex = permissionText.toInt(); // "0" -> 0, "1" -> 1, "2" -> 2
    ui->per_combo->setCurrentIndex(permissionIndex);


    QTableWidgetItem* idItem = ui->tw_dept->item(row,0);
    if(idItem){
        dept_id = idItem->text().toInt();
    }
    qDebug()<<"선택된 아이디: " <<dept_id;
}

void dept::send_json_to_server_to_read_deptList(){

    QString path_ = QString(FILE_PATH)+"/read_dept.json";
    // json 파일 읽기
    std::ifstream file(path_.toStdString());
    if(!file.is_open()){
        std::cerr <<"파일을 열수 없습니다.\n";
        exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonData = buffer.str();

    //소켓 생성
    int sock = socket(AF_INET, SOCK_STREAM,0);
    if(sock<0){
        perror("소캣 생성 실패!");
        exit(1);
    }

    //서버 주소 설정
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    //서버에 연결
    if( ::connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr))<0){
        perror("서버 연결 실패");
        ::close(sock);
        exit(1);
    }

    // qDebug()<< jsonData ;

    // json 데이터 전송
    ssize_t sentBytes = send(sock, jsonData.c_str(), jsonData.size(), 0);
    if(sentBytes<0){
        perror("전송 실패");
    }else{
        std::cout<<"json 전송 완료 ("<<sentBytes<< "바이트\n";
    }

    // 전송후 응답 처리
    std::string responseStr;

    while(true){
        char buffer_recv[4096] = {0};
        ssize_t recvBytes = recv(sock, buffer_recv, sizeof(buffer_recv)-1,0); // -1은 널 문자 공간 확보용

        if(recvBytes <0){
            perror("서버응답 수신 실패");
            break;

        }else if(recvBytes ==0){
            std::cerr <<"서버가 연결을 종료함 .\n";
            break;
        }
        buffer_recv[recvBytes] = '\0';
        responseStr +=buffer_recv;
    }
    std::cout << "서버응답 수신 완료: " <<responseStr <<std::endl;


    try{
        //부서 서버 요청을 응답받았을때 뭘해야할까?
        json response_json  = json::parse(responseStr);
        std::cout<< "파싱된 json 응답: \n" << response_json.dump(4)<< std::endl;

        // 확인되면 전부 이제 변수에 담아서 tableWidget에 담아서 출력하자
        QTableWidget* table = ui->tw_dept;
        table->horizontalHeader()->setStretchLastSection(true);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        table->setColumnCount(4);


        table->setHorizontalHeaderLabels({
            // "ID", "시작일시", "종료일시", "이름", "단체ID", "단체명", "행사상세 내용"
           "부서 아이디","권한 레벨","로그인 아이디","부서명",
        });

        table->setRowCount(response_json.size());

        for(auto i=0u; i < response_json.size(); ++i){
            const auto& item = response_json[i];

            table->setItem(i, 0, new QTableWidgetItem(QString::number(static_cast<int>(item["DEPT_ID"]))));
            table->setItem(i, 1, new QTableWidgetItem(QString::number(static_cast<int>(item["PERMISSION_LEVEL"]))));
            table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(item["LOGIN_ID"])));
            table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(item["DEPT_NAME"])));

        }
        table->resizeColumnsToContents();
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    }catch(json::parse_error& e){
        std::cerr<<"json 파싱 오류 : " <<e.what() <<std::endl;
    }
    ::close(sock);
}

void dept::make_dept(){

    dept_name = ui->deptName_le->text();
    dept_login_id = ui->dept_user_id->text();
    dept_login_pass = ui->dept_user_pass_le->text();

    nlohmann::json j;
    j["type"] = "req_dept_create";

    nlohmann::json data;
    data["DEPT_NAME"] = dept_name.toStdString();
    // data["manager_name"] = manager_name.toStdString();

    data["LOGIN_ID"] = dept_login_id.toStdString();
    data["LOGIN_PW"] = dept_login_pass.toStdString();
    data["PERMISSION_LEVEL"] = permission;
    j["data"] = data;

    QString jsonString = QString::fromStdString(j.dump(4));
    QString filePath = QString(FILE_PATH) + "/make_dept.json";
    QFile file(filePath);

    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out << jsonString;
        file.close();
        qDebug()<<"JSON saved to " <<filePath;

    }else{
        qWarning() << "Failed to save json to file";
    }
    // 서버로 json 요청 보내는 함수 호출해야함 !
    qDebug()<< jsonString;
    this->send_json_to_server_for_regist_dept();

    //새로고침
    this->send_json_to_server_to_read_deptList();
}

// 서버로 부서를 등록 하거나 수정  호출할 함수
void dept::send_json_to_server_for_regist_dept(){

    QString path_ = QString(FILE_PATH)+ "/make_dept.json";

    std::ifstream file(path_.toStdString());
    if(!file.is_open()){
        std::cerr<<"파일을 열수 없습니다. \n";
        exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonData = buffer.str();

    //소켓 생성
    int sock = socket(AF_INET, SOCK_STREAM,0);
    if(sock<0){
        perror("소캣 생성 실패!");
        exit(1);
    }
    //서버 주소 설정
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    //서버에 연결
    if( ::connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr))<0){
        perror("서버 연결 실패");
        ::close(sock);
        exit(1);
    }
    // json 데이터 전송
    ssize_t sentBytes = send(sock, jsonData.c_str(), jsonData.size(), 0);
    if(sentBytes<0){
        perror("전송 실패");
    }else{
        std::cout<<"json 전송 완료 ("<<sentBytes<< "바이트\n";
    }

    std::string responseStr;

    while(true){
        char buffer_recv[4096] = {0};
        ssize_t recvBytes = recv(sock, buffer_recv, sizeof(buffer_recv)-1,0); // -1은 널 문자 공간 확보용

        if(recvBytes <0){
            perror("서버응답 수신 실패");
            break;

        }else if(recvBytes ==0){
            std::cerr <<"서버가 연결을 종료함 .\n";
            break;
        }
        buffer_recv[recvBytes] = '\0';
        responseStr +=buffer_recv;

    }
    std::cout << "서버응답 수신 완료: " <<responseStr <<std::endl;

    try{
        // 추후 부서 등록후 서버로부터 온 응답으로 뭘할지 고민!
        json response_json = json::parse(responseStr);
        std::cout<< "파싱된 json 응답 : \n" << response_json.dump(4) << std::endl;


        // ui->res_le->setText(QString::fromStdString(response_json[0]["message"]));

        //listing을 새로고침하는게?
    }catch(json::parse_error& e){
        std::cerr<<"json 파싱오류: "<< e.what() << std::endl;
    }
    ::close(sock);

}


void dept::onPermissionComboBoxChanged(int index){
    // 0 일반유저 1 crud 2 root(god)
    permission = index;
    qDebug() << "선택된 권한 값 (인덱스): " <<permission;

    if(permission ==0){
        qDebug() <<"권한이 일반으로 선택되었습니다.";
    }else if(permission ==1){
        qDebug() <<"권한이 관리자 으로 선택되었습니다.";
    }else if(permission ==2){
        qDebug() <<"권한이 슈퍼유저  으로 선택되었습니다.";
    }

}


