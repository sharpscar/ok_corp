#ifndef DEPT_H
#define DEPT_H

#include <QTableWidget>
#include <QWidget>

#include <arpa/inet.h>
#include <json.hpp>
#include <QFile>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <QMessageBox>
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
    void onTableItemClicked(int row, int column);
    void update_dept();
    void make_req_json_for_deptList();
    void send_json_to_server_to_read_deptList();
    void delete_dept();
    void performDelete(int);
private:
    Ui::dept *ui;

    QString dept_name;
    int permission;
    int dept_id;
    QString dept_login_id;
    QString dept_login_pass;



};

#endif // DEPT_H
