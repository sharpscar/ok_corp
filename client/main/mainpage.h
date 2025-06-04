#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "schedule.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainPage;
}
QT_END_NAMESPACE

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = nullptr);
    ~MainPage();
     void changeSchedulePage();

private:
    Ui::MainPage *ui;
    Schedule *schedulePage; // 스케줄 페이지 인스턴스 선언
};
#endif // MAINPAGE_H
