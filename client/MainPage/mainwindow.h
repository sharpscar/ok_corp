#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "schedule.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Schedule *schedulePage; // 스케줄 페이지 인스턴스 선언
    void changeSchedulePage();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
