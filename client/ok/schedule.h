#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QMainWindow>
#include <QCalendarWidget>

#include <QDebug>
#include <QGroupBox>
#include <QDialog>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QDate> // QDate 클래스를 사용하기 위해 포함
#include <QFile>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <json.hpp>
#include <QMessageBox>

#define FILE_PATH "/home/scar/ok_corp/client/json/"
#define SERVER_IP "localhost"            //"10.10.20.101"
#define SERVER_PORT 9957

QT_BEGIN_NAMESPACE
namespace Ui {
class Schedule;
}
QT_END_NAMESPACE

class Schedule : public QMainWindow
{
    Q_OBJECT

public:
    Schedule(QWidget *parent = nullptr);
    QCalendarWidget m_calendarWidget;
    ~Schedule();
    void send_json_to_server();

    void req_event_json_for_first_page();
    void send_json_to_server_for_read_schedule();

private:
    QString s_date;                         //행사시작일
    QString e_date;                         //행사종료일
    QString event_name;                     //행사명
    QString org_name;             //행사단체
    int organization_id;                     //단체아이디
    QString event_detail;                   //행사 상세 (개요)
    int schedule_id;
    Ui::Schedule *ui;

    void make_schedule();
    void update_schedule();
    void delete_schedule();
    void performDelete(int);
private slots:

    void onCalendarDateSelected_start(const QDate &date);
    void onCalendarDateSelected_end(const QDate &date);
    void onTableItemClicked(int row, int column);


};
#endif // SCHEDULE_H
