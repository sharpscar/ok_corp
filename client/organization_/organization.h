#ifndef ORGANIZATION_H
#define ORGANIZATION_H

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

#include <QWidget>

#define FILE_PATH "/home/scar/ok_corp/client/json/"
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 9957

QT_BEGIN_NAMESPACE
namespace Ui {
class organization;
}
QT_END_NAMESPACE

class organization : public QWidget
{
    Q_OBJECT

public:
    organization(QWidget *parent = nullptr);
    ~organization();
    void req_organization_read_for_first_page();
    void send_json_to_server_for_read_organization();

private:
    int organization_id;
    int dept_id;

    QString organization_name;
    QString president_name;
    QString district;
    QString org_intro;
    QString manager_name;
    QString phone;
    QString established;

    Ui::organization *ui;
};
#endif // ORGANIZATION_H
