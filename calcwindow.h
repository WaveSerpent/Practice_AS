#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QMainWindow>
#include "cmath"

QT_BEGIN_NAMESPACE
namespace Ui {
class CalcWindow;
}
QT_END_NAMESPACE

class CalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalcWindow(QWidget *parent = nullptr);
    ~CalcWindow();

private:
    Ui::CalcWindow *ui;

private slots:
    void digits_numbers();
    void comma_button_click();
    void math_operations();
    void on_bt_AC_clicked();
    void on_bt_equal_clicked();
    void on_bt_backspace_clicked();
    void on_bt_plus_minus_clicked();
};
#endif // CALCWINDOW_H
