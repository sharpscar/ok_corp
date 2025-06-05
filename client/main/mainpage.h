#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "schedule.h"
#include "dept.h"

#include <QWidget>
#include <QStackedWidget>

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
    void initializeStackedWidget();
    void change_to_SchedulePage();
    void change_to_Dept_Page();

private:
    Ui::MainPage *ui;
    Schedule *schedulePage; // 스케줄 페이지 인스턴스 선언
    dept *deptPage;
};
#endif // MAINPAGE_H
