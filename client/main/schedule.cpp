#include "schedule.h"
#include "ui_schedule.h"

#include <QListWidget>
#include <QTableWidget>


// #define SERVER_IP "127.0.0.1"
// #define SERVER_PORT 9957

using json = nlohmann::json;

Schedule::Schedule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);
    connect(ui->reg_sch_btn_2, &QPushButton::clicked, this, &Schedule::make_schedule);

    ui->stackedWidget->setCurrentIndex(0);

    //서버에 json 생성후 요청을 보낸다.
    this->req_event_json_for_first_page();
    connect(ui->tw_schedule, &QTableWidget::cellClicked, this, &Schedule::onTableItemClicked);
    connect(ui->s_update_btn, &QPushButton::clicked, this, &Schedule::update_schedule);
    connect(ui->s_delete_btn, &QPushButton::clicked, this, &Schedule::delete_schedule);
    connect(ui->call_input_btn, &QPushButton::clicked, this, [this](){
        ui->groupBox_2->show();
    });

    ui->s_date_edit->setCalendarPopup(true);
    ui->e_date_edit->setCalendarPopup(true);




}
void Schedule::delete_schedule(){

    // qDebug()<<schedule_id;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this,
        "삭제 확인",
        "정말 삭제하시겠습니까?",
        QMessageBox::Yes | QMessageBox::No
        );

    if(reply == QMessageBox::Yes){
        //삭제수행!
        performDelete(event_id);
    }

}
void Schedule::performDelete(int event_id){

    //삭제 json 생성
    json j,data;

    j["type"] = "req_event_delete";

    data["EVENT_ID"] = event_id;
    j["data"] = data;

    QString jsonString = QString::fromStdString(j.dump(4));
    QString filePath =QString(FILE_PATH)+"/make_schedule.json";



    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out <<jsonString;
        file.close();
        qDebug()<<"JSON saved to" <<filePath;

    }else{
        qWarning()<<"Failed to save json to file";

    }
    //요청 서버로 전송
    this->send_json_to_server();

    //리로드
    this->req_event_json_for_first_page();
    this->send_json_to_server_for_read_schedule();
}

void Schedule::update_schedule(){
    qDebug()<<"수정버튼 클릭";

    // 1 json 파일 생성 - schedule_id 가지고 가야함!! 중요
    json j;

    j["type"] = "req_event_update";

    json data;

    if(!event_id)
    {
        qDebug()<< "선택된 행의 행사 id값이 선택되지 않았습니다. 테이블 위젯을 클릭해야 설정됩니다.";
    }

    data["EVENT_ID"] = event_id;
    //단체명
    // data["org_name"] = ui->le_org->text().toStdString();

    //시작일처리
    QDate s_date_ =  ui->s_date_edit->date();
    QTime s_time_ = ui->s_time_edit->time();
    QDateTime s_datetime_(s_date_, s_time_);
    //종료일 처리
    QDate e_date_ = ui->e_date_edit->date();
    QTime e_time_ = ui->e_time_edit->time();
    QDateTime e_datetime_(e_date_, e_time_);

    data["START_DATE"] = s_datetime_.toString("yyyy-MM-dd HH:mm:ss").toStdString();
    data["END_DATE"] = e_datetime_.toString("yyyy-MM-dd HH:mm:ss").toStdString();





    //담당자 , 담당자 연락처 또한 업데이트 되면 좋겠지만 그건 단체관리에서 하는게 좀더 정확하다.여기서는 행사만 관리한다.
    data["EVENT_NAME"] = ui->s_name->text().toStdString();
    // data["organization_id"]  단체 아이디 << 이것 또한 임의로 설정한다.
    data["GROUP_ID"] = 1234;
    data["DEPT_ID"] = 1234;
    data["DESCRIPTION"] = ui->s_detail->toPlainText().toStdString();

    j["data"] = data;
    //json 문자열로 변환
    QString jsonString = QString::fromStdString(j.dump(4));
    QString filePath =QString(FILE_PATH)+"/make_schedule.json";

    qDebug()<< jsonString;
    qDebug()<< filePath;

    QFile file(filePath);

    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out <<jsonString;
        file.close();
        qDebug()<<"JSON saved to" <<filePath;

    }else{
        qWarning()<<"Failed to save json to file";

    }

    this->send_json_to_server();
    // 2. 서버로 수정 요청

    ui->groupBox_2->hide();
    //리로드
    this->req_event_json_for_first_page();
    this->send_json_to_server_for_read_schedule();


}

void Schedule::onTableItemClicked(int row, int column){

    ui->groupBox_2->show();

    // 단체명
    ui->le_org->setText(ui->tw_schedule->item(row, 0)->text());

    //시작일
    // ui->le_start->setText(ui->tw_schedule->item(row, 3)->text());
    qDebug()<<ui->tw_schedule->item(row, 3)->text() <<"\n";

    QString s_fullDateTimeString = ui->tw_schedule->item(row, 3)->text();
    QStringList s_parts = s_fullDateTimeString.split(" ");
    QString s_date = s_parts.at(0);
    QString s_time = s_parts.at(1);
    QDate s_date_ = QDate::fromString(s_date, "yyyy-MM-dd");
    QTime s_time_ = QTime::fromString(s_time, "HH:mm:ss");

    QString e_fullDateTimeString = ui->tw_schedule->item(row, 4)->text();
    QStringList e_parts = e_fullDateTimeString.split(" ");
    QString e_date = e_parts.at(0);
    QString e_time = e_parts.at(1);
    QDate e_date_ = QDate::fromString(e_date, "yyyy-MM-dd");
    QTime e_time_ = QTime::fromString(e_time, "HH:mm:ss");



    ui->s_date_edit->setDate(s_date_);
    ui->e_date_edit->setDate(e_date_);
    ui->s_time_edit->setTime(s_time_);
    ui->e_time_edit->setTime(e_time_);
    //종료일
    // ui->le_end->setText(ui->tw_schedule->item(row, 4)->text());

    //담당자 이건 해당 행사 단체에 관련한 컬럼이다 -> organization_id를 통해서 단체 테이블의 담당 부서를 조회하고 부서의 담당자정보를 가져와야 한다.

    //담당 연락처

    //행사명
    ui->s_name->setText(ui->tw_schedule->item(row, 1)->text());
    //행사 상세
    ui->s_detail->setText(ui->tw_schedule->item(row, 2)->text());
    //단체 아이디


    QTableWidgetItem* idItem = ui->tw_schedule->item(row, 6);
    if(idItem){
        event_id = idItem->text().toInt();
    }
    qDebug()<<"선택된 아이디: "<<event_id;
}

void Schedule::req_event_json_for_first_page(){

    json j;
    j["type"]= "req_event_read";

    //json 문자열로 변환
    QString jsonString = QString::fromStdString(j.dump(4));

    QString filePath =QString(FILE_PATH)+"/read_schedule.json";

    QFile file(filePath);

    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out <<jsonString;
        file.close();
        qDebug()<<"JSON saved to" <<filePath;

    }else{
        qWarning()<<"Failed to save json to file";

    }

    this->send_json_to_server_for_read_schedule();
    qDebug()<<"여기까지 왔나?";
}


// void Schedule::onCalendarDateSelected_start(const QDate &date){
//     qDebug()<< date;

//     ui->s_day_le->setText(date.toString("yyyy-MM-dd"));
//     s_date = date.toString();
//     //텍스트 에디터 창 뜨고  제목도 뜨고
// }

// void Schedule::onCalendarDateSelected_end(const QDate &date){
//     qDebug()<< date;

//     ui->e_day_le->setText(date.toString("yyyy-MM-dd"));
//     e_date = date.toString();
//     //텍스트 에디터 창 뜨고  제목도 뜨고
// }

void Schedule::make_schedule(){

    qDebug()<<"입력버튼                 버튼 클릭";

    // 1 json 파일 생성 - schedule_id 가지고 가야함!! 중요
    json j;

    j["type"] = "req_event_create";

    json data;
    // data["org_name"] = ui->le_org->text().toStdString();

    //시작일처리
    QDate s_date_ =  ui->s_date_edit->date();
    QTime s_time_ = ui->s_time_edit->time();
    QDateTime s_datetime_(s_date_, s_time_);
    //종료일 처리
    QDate e_date_ = ui->e_date_edit->date();
    QTime e_time_ = ui->e_time_edit->time();
    QDateTime e_datetime_(e_date_, e_time_);



    data["START_DATE"] = s_datetime_.toString("yyyy-MM-dd HH:mm:ss").toStdString();
    data["END_DATE"] = e_datetime_.toString("yyyy-MM-dd HH:mm:ss").toStdString();

    //담당자 , 담당자 연락처 또한 업데이트 되면 좋겠지만 그건 단체관리에서 하는게 좀더 정확하다.여기서는 행사만 관리한다.
    data["EVENT_NAME"] = ui->s_name->text().toStdString();
    data["DESCRIPTION"] = ui->s_detail->toPlainText().toStdString();
    // data["organization_id"]  단체 아이디 << 행사 리스트 가져올때 단체리스트를 가져와서 셀렉트 박스에 넣어두는게 좋겠다.
    data["GROUP_ID"] = 1234;
    data["DEPT_ID"] = 1234;

    j["data"] = data;
    //json 문자열로 변환
    QString jsonString = QString::fromStdString(j.dump(4));
    QString filePath =QString(FILE_PATH)+"/make_schedule.json";

    qDebug()<< filePath <<"\n";

    qDebug()<<jsonString <<"\n";

    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out <<jsonString;
        file.close();
        qDebug()<<"JSON saved to" <<filePath;

    }else{
        qWarning()<<"Failed to save json to file";

    }
    ui->groupBox_2->hide();



    this->send_json_to_server();

    this->send_json_to_server_for_read_schedule();
}

void Schedule::send_json_to_server_for_read_schedule(){

    QString path_ = QString(FILE_PATH)+"/read_schedule.json";
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

    // qDebug()<< "send_json_to_server_for_read_schedule() 함수에서 데이터 전송 직전까지 실행";
    // qDebug()<< jsonData ;

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
        json response_json = json::parse(responseStr);
        std::cout<< "파싱된 json 응답 : \n" << response_json.dump(4) << std::endl;


        // 확인되면 전부 이제 변수에 담아서 tableWidget에 담아서 출력하자
        QTableWidget* table = ui->tw_schedule;

        table->setColumnCount(7);
        table->setHorizontalHeaderLabels({
            // "ID", "시작일시", "종료일시", "이름", "단체ID", "단체명", "행사상세 내용"
            "그룹아이디","행사명","행사 상세 내용","시작일시","종료일시","단체_id","id"
        });

        // std::string jsonStr = response_json;    //  이줄에서 난 오류 response_json이게 JSON 객체 혹은 배열인데 이걸 또 문자열로 직접 변환하려고 해서 난 오류이다.
        // json scheduleArray = json::parse(jsonStr);
        // json& scheduleArray = response_json;

        table->setRowCount(response_json.size());

        for(auto i=0u; i < response_json.size(); ++i){
            const auto& item = response_json[i];

            table->setItem(i, 0, new QTableWidgetItem(QString::number(static_cast<int>(item["GROUP_ID"]))));
            table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(item["EVENT_NAME"])));
            table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(item["DESCRIPTION"])));
            table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(item["START_DATE"])));
            table->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(item["END_DATE"])));
            table->setItem(i, 5, new QTableWidgetItem(QString::number(static_cast<int>(item["GROUP_ID"]))));
            table->setItem(i, 6, new QTableWidgetItem(QString::number(static_cast<int>(item["EVENT_ID"]) )));

        }

        table->resizeColumnsToContents();
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);


    }catch(json::parse_error& e){
        std::cerr<<"json 파싱 오류 : " <<e.what() <<std::endl;

    }
    ::close(sock);
}



void Schedule::send_json_to_server(){

    QString path_ = QString(FILE_PATH)+"/make_schedule.json";

    qDebug()<<"전송전 어디로 보내는지? "<< path_;

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

    // json 데이터 전송
    ssize_t sentBytes = send(sock, jsonData.c_str(), jsonData.size(), 0);
    if(sentBytes<0){
        perror("전송 실패");
    }else{
        std::cout<<"json 전송 완료 ("<<sentBytes<< "바이트\n";
    }
    ::close(sock);

}




Schedule::~Schedule()
{
    delete ui;
}
