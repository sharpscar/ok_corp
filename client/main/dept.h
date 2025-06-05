#ifndef DEPT_H
#define DEPT_H

#include <QWidget>

#include <arpa/inet.h>
#include <json.hpp>
#include <QFile>
#include <fstream>
#include <iostream>
#include <unistd.h>

namespace Ui {
class dept;
}


#define FILE_PATH "/home/scar/ok_corp/client/main/json"
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 9957

class dept : public QWidget
{
    Q_OBJECT

public:
    explicit dept(QWidget *parent = nullptr);
    void onPermissionComboBoxChanged(int);
    ~dept();
    void make_dept();
    void send_json_to_server_for_regist_dept();
private:
    Ui::dept *ui;
    void req_dept_json_for_first_page();

    QString dept_name;
    QString manager_name;
    int permission;
    QString dept_id;
    QString dept_pass;




};

#endif // DEPT_H
