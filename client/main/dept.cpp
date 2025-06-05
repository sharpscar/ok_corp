#include "dept.h"
#include "ui_dept.h"

#include <json.hpp>

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
}

dept::~dept()
{
    delete ui;
}
void dept::make_dept(){
    /*
    QString dept_name;
    QString manager_name;
    int permission;
    QString dept_id;
    QString dept_pass;*/
    dept_name = ui->deptName_le->text();
    manager_name = ui->manName_le->text();
    dept_id = ui->dept_user_id->text();
    dept_pass = ui->dept_user_pass_le->text();

    nlohmann::json j;
    j["type"] = "req_dept_create";

    nlohmann::json data;
    data["dept_name"] = dept_name.toStdString();
    data["manager_name"] = manager_name.toStdString();
    data["dept_name"] = dept_name.toStdString();
    data["dept_user_id"] = dept_id.toStdString();
    data["dept_user_pass"] = dept_pass.toStdString();
    data["permission"] = permission;
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


