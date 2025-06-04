#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "loginwindow.h"
#include "schedule.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // void changeSchedulePage();
    void changeSchedulePage();

private:
    Ui::MainWindow *ui;

    Schedule *schedulePage; // 스케줄 페이지 인스턴스 선언

private slots:
    // void showMainContentPage();
    // void showSchedulePage();


};

#endif // MAINWINDOW_H
