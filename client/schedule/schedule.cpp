#include "schedule.h"
#include "ui_schedule.h"

#include <QListWidget>
#include <QTableWidget>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 9957

using json = nlohmann::json;

Schedule::Schedule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Schedule)
{
    ui->setupUi(this);

    QDialog *calendarDialog = new QDialog(this);
    calendarDialog->setWindowTitle("날짜 선택");
    calendarDialog->setWindowModality(Qt::ApplicationModal);
    calendarDialog->setFixedSize(500, 500);

    QCalendarWidget *popupCalendaer = new QCalendarWidget(calendarDialog);
    QVBoxLayout *dialogLayout = new QVBoxLayout(calendarDialog);
    ui->verticalLayout->addWidget(popupCalendaer);
    calendarDialog->setLayout(dialogLayout);

    QDialog *calendarDialog_end = new QDialog(this);
    calendarDialog_end->setWindowTitle("날짜 선택");
    calendarDialog_end->setWindowModality(Qt::ApplicationModal);
    calendarDialog_end->setFixedSize(500, 500);

    QCalendarWidget *popupCalendaer2 = new QCalendarWidget(calendarDialog);
    QVBoxLayout *dialogLayout2 = new QVBoxLayout(calendarDialog);
    ui->verticalLayout_3->addWidget(popupCalendaer2);
    calendarDialog->setLayout(dialogLayout2);

    // calendarDialog->show();
    // calendarDialog_end->show();



    connect(popupCalendaer, &QCalendarWidget::clicked, this, &Schedule::onCalendarDateSelected_start);
    connect(popupCalendaer2, &QCalendarWidget::clicked, this, &Schedule::onCalendarDateSelected_end);
    connect(ui->reg_sch_btn, &QPushButton::clicked, this, &Schedule::make_schedule);


    // 0번 페이지가 행사 리스팅
    // 1번 페이지가 행사 등록
    ui->stackedWidget->setCurrentIndex(0);


    //서버에 json 생성후 요청을 보낸다.
    this->req_event_json_for_first_page();
    connect(ui->tw_schedule, &QTableWidget::cellClicked, this, &Schedule::onTableItemClicked);
    connect(ui->s_update_btn, &QPushButton::clicked, this, &Schedule::update_schedule);
    connect(ui->s_delete_btn, &QPushButton::clicked, this, &Schedule::delete_schedule);

    ui->groupBox_2->hide();

   /*


    listWidget->addItem("행사 1: 수영 대회");
    listWidget->addItem("행사 2: 독서 토론회");

*/


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
        performDelete(schedule_id);
    }

}
void Schedule::performDelete(int schedule_id){

    //삭제 json 생성
    json j,data;

    j["type"] = "req_event_delete";

    data["schedule_id"] = schedule_id;
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
}

void Schedule::update_schedule(){
    qDebug()<<"수정버튼 클릭";

    // 1 json 파일 생성 - schedule_id 가지고 가야함!! 중요
    json j;

    j["type"] = "req_event_update";

    json data;

    if(!schedule_id)
    {
        qDebug()<< "선택된 행의 행사 id값이 선택되지 않았습니다. 테이블 위젯을 클릭해야 설정됩니다.";
    }

    data["schedule_id"] = schedule_id;
    data["org_name"] = ui->le_org->text().toStdString();
    data["s_date"] = ui->le_start->text().toStdString();
    data["e_date"] = ui->le_end->text().toStdString();
    //담당자 , 담당자 연락처 또한 업데이트 되면 좋겠지만 그건 단체관리에서 하는게 좀더 정확하다.여기서는 행사만 관리한다.
    data["event_name"] = ui->s_name->text().toStdString();
    // data["organization_id"]  단체 아이디 << 이것 또한 임의로 설정한다.
    data["organization_id"] = 1234;
    data["event_detail"] = ui->s_detail->toPlainText().toStdString();

    j["data"] = data;
    //json 문자열로 변환
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

    this->send_json_to_server();
    // 이건 수정후 테이블 위젯을 새로고침하는 내용!
    this->send_json_to_server_for_read_schedule();
    // 2. 서버로 수정 요청



    // 3. 서버에서 쿼리 수행

    // 4. 응답
}

void Schedule::onTableItemClicked(int row, int column){

    ui->groupBox_2->show();

    // 단체명
    ui->le_org->setText(ui->tw_schedule->item(row, 0)->text());
    //시작일
    ui->le_start->setText(ui->tw_schedule->item(row, 3)->text());
    //종료일
    ui->le_end->setText(ui->tw_schedule->item(row, 4)->text());

    //담당자 이건 해당 행사 단체에 관련한 컬럼이다 -> organization_id를 통해서 단체 테이블의 담당 부서를 조회하고 부서의 담당자정보를 가져와야 한다.

    //담당 연락처

    //행사명
    ui->s_name->setText(ui->tw_schedule->item(row, 1)->text());
    //행사 상세
    ui->s_detail->setText(ui->tw_schedule->item(row, 2)->text());
    //단체 아이디


    QTableWidgetItem* idItem = ui->tw_schedule->item(row, 6);
    if(idItem){
        schedule_id = idItem->text().toInt();
    }
    qDebug()<<"선택된 아이디: "<<schedule_id;
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


void Schedule::onCalendarDateSelected_start(const QDate &date){
    qDebug()<< date;

    ui->s_day_le->setText(date.toString("yyyy-MM-dd"));
    s_date = date.toString();
    //텍스트 에디터 창 뜨고  제목도 뜨고
}

void Schedule::onCalendarDateSelected_end(const QDate &date){
    qDebug()<< date;

    ui->e_day_le->setText(date.toString("yyyy-MM-dd"));
    e_date = date.toString();
    //텍스트 에디터 창 뜨고  제목도 뜨고
}

void Schedule::make_schedule(){

    // json생성
    s_date = ui->s_day_le->text();
    QDate Qs_date = QDate::fromString(s_date,"yyyy-MM-dd");
    e_date = ui->e_day_le->text();
    QDate Qe_date = QDate::fromString(e_date,"yyyy-MM-dd");

    QString s_time = ui->s_timeEdit->text();
    QString e_time = ui->e_timeEdit->text();
    QTime Qs_time = QTime::fromString(s_time, "HH:mm:ss");
    QTime Qe_time = QTime::fromString(e_time, "HH:mm:ss");

    QDateTime s_datetime;
    s_datetime.setDate(Qs_date);
    s_datetime.setTime(Qs_time);

    QDateTime e_datetime;
    e_datetime.setDate(Qe_date);
    e_datetime.setTime(Qe_time);

    event_name = ui->event_name_le->text();
    event_detail = ui->event_info_le->toPlainText();

    //임의 데이터
    org_name = "ok상사";
    organization_id = 1234;

    json j;
    j["type"]= "req_event_create";

    // 여기서 시작일시 , 종료일시를 시간 값을 가져와서  합쳐서 넣어야 한다!
    json data;
    data["s_date"] = s_datetime.toString("yyyy-MM-dd HH:mm:ss").toStdString();
    data["e_date"] = e_datetime.toString("yyyy-MM-dd HH:mm:ss").toStdString();

    data["event_name"] = event_name.toStdString();
    data["event_organization"] = org_name.toStdString();
    data["organization_id"]= organization_id;
    data["event_detail"]=event_detail.toStdString();

    j["data"] = data;
    //json 문자열로 변환
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

    this->send_json_to_server();

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
            "단체명","행사명","행사 상세 내용","시작일시","종료일시","단체_id","id"
        });

        // std::string jsonStr = response_json;    //  이줄에서 난 오류 response_json이게 JSON 객체 혹은 배열인데 이걸 또 문자열로 직접 변환하려고 해서 난 오류이다.
        // json scheduleArray = json::parse(jsonStr);
        // json& scheduleArray = response_json;

        table->setRowCount(response_json.size());

        for(auto i=0u; i < response_json.size(); ++i){
            const auto& item = response_json[i];

            table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(item["event_organization"])));
            table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(item["s_name"])));
            table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(item["event_detail"])));
            table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(item["s_start_date"])));
            table->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(item["s_end_date"])));
            table->setItem(i, 5, new QTableWidgetItem(QString::number(static_cast<int>(item["organization_id"]) )));
            table->setItem(i, 6, new QTableWidgetItem(QString::number(static_cast<int>(item["schedule_id"]) )));

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
