#include "organization.h"
#include "ui_organization.h"

using json = nlohmann::json;

organization::organization(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::organization)
{
    ui->setupUi(this);
    this->req_organization_read_for_first_page();
}

organization::~organization()
{
    delete ui;
}

void organization::req_organization_read_for_first_page(){

    json j;
    j["type"]="req_organi_read";

    // 4는 들여쓰기 칸수다.
    QString jsonString = QString::fromStdString(j.dump(4));
    QString filePath  =QString(FILE_PATH)+"/read_organizaion.json";
    QFile file(filePath);

    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        out <<jsonString;
        file.close();
        qDebug()<<"Json saved to "<< filePath;
    }else{
        qWarning()<<"Failed to save json to file";
    }
    // this->send_json_to_server_for_read_organization();  // 서버송신
}

void organization::send_json_to_server_for_read_organization(){
    QString path_  = QString(FILE_PATH) + "/read_organization.json";

    std::ifstream file(path_.toStdString());
    if(!file.is_open()){
        std::cerr <<"파일을 열수 없습니다.\n";
        exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonData = buffer.str();

    //소켓 생성
    int sock =  socket(AF_INET, SOCK_STREAM, 0);
    if(sock<0){
        perror("소켓 생성 실패!");
        exit(1);
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    //서버에 연결
    if(::connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr))<0){
        perror("서버 연결 실패");
        ::close(sock);
        exit(1);

    }

    //json 데이터 전송
    ssize_t sentBytes = send(sock, jsonData.c_str(), jsonData.size(), 0);
    if(sentBytes<0){
        perror("전송 실패");

    }else{
        std::cout<<"json 전송완료 ("<<sentBytes<< "바이트\n";
    }

    std::string responseStr;

    while(true){
        char buffer_recv[4096] = {0};
        ssize_t recvBytes = recv(sock, buffer_recv, sizeof(buffer_recv)-1,0); //  -1 ㅡㅇ ㄴ널문자 공간확보용

        if(recvBytes <0){
            perror("서버응답 수신 실패");
            break;
        }else if(recvBytes ==0){
            std::cerr <<"서버가 연결을 종료함. \n";
        }
        buffer_recv[recvBytes]='\0';
        responseStr +=buffer_recv;
    }

}


















