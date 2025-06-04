#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include "dbmanager.h"
#include <QSqlQuery>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow) {
    ui->setupUi(this);
    DBManager::connect();
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_loginButton_clicked() {
    QString id = ui->idEdit->text();
    QString pw = ui->pwEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM db2.member WHERE m_id = :id AND m_pass = :pw");
    query.bindValue(":id", id);
    query.bindValue(":pw", pw);
    if (query.exec() && query.next()) {
        QMessageBox::information(this, "로그인 성공", "로그인에 성공하였습니다.");
        MainWindow *main = new MainWindow();
        main->show();
        this->close();
    } else {
        QMessageBox::warning(this, "로그인 실패", "아이디 또는 비밀번호가 틀렸습니다.");
    }
}
