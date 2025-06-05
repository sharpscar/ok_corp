#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    setWindowTitle("광산구청 통합관리 시스템");




    //위젯 인스턴스 생성
    // 부모를 QStackedWidget으로 설정하거나 nullptr로 설정후  나중에 stackedWidget에 추가
    schedulePage = new Schedule(this);
    deptPage = new dept(this);

    initializeStackedWidget();

    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainPage::change_to_SchedulePage);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainPage::change_to_Dept_Page);

}
void MainPage::initializeStackedWidget(){
    // 이작업은 프로그램 시작시 단 한번만 수행!
    ui->stackedWidget->addWidget(schedulePage);
    ui->stackedWidget->addWidget(deptPage);

    // (초기)부서 페이지를 기본으로  - 부서를 개발중..
    ui->stackedWidget->setCurrentWidget(deptPage);
    qDebug()<<"QStackedWidget 초기화 완료 스케쥴 페이지가 기본으로 설정됨 ";

}

MainPage::~MainPage()
{
    delete ui;


}
void MainPage::change_to_SchedulePage(){

    // 1. QStackedWidget에서 Schedule 위젯을 표시합니다.
    ui->stackedWidget->setCurrentWidget(schedulePage);
    qDebug() << "스케줄 페이지로 전환.";

    // 행사 crud 를 보여주는 코드
    // ui->stackedWidget->currentWidget()->layout()->addWidget(schedulePage);
    qDebug() << " 스케쥴 페이지를 메인에 표시.";
}
void MainPage::change_to_Dept_Page(){

    // 1. QStackedWidget에서 Schedule 위젯을 표시합니다.
    ui->stackedWidget->setCurrentWidget(deptPage);

    // ui->stackedWidget->currentWidget()->layout()->addWidget(deptPage);

    qDebug() << "dept_page를 메인에 표시.";
}
