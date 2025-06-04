#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    setWindowTitle("광산구청 통합관리 시스템");

    //스케쥴 객체 생성!
    schedulePage = new Schedule(this);
    // ui->stackedWidget->currentWidget()->layout()->addWidget(schedulePage);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainPage::changeSchedulePage);
}

MainPage::~MainPage()
{
    delete ui;
}
void MainPage::changeSchedulePage(){

    // 1. QStackedWidget에서 Schedule 위젯을 표시합니다.
    ui->stackedWidget->setCurrentWidget(schedulePage);
    qDebug() << "스케줄 페이지로 전환.";
    // 2. Schedule 위젯의 데이터를 로드하는 함수를 호출합니다.
    //    이 함수는 Schedule 클래스 내부에 정의되어 있어야 합니다.
    // schedulePage->req_event_json_for_first_page();

    // 행사 crud 를 보여주는 코드
    ui->stackedWidget->currentWidget()->layout()->addWidget(schedulePage);
    qDebug() << "req_event_json_for_first_page() 호출됨.";
}
