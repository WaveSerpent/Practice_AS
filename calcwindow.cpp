#include "calcwindow.h"
#include "./ui_calcwindow.h"

CalcWindow::CalcWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalcWindow)
{
    ui->setupUi(this);
    ui->bt_backspace->setIcon(QIcon(":/icons/backspace.svg"));
    ui->bt_backspace->setIconSize(QSize(32,32));

    connect(ui->bt_0,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_1,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_2,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_3,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_4,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_5,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_6,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_7,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_8,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_9,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->bt_plus,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->bt_minus,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->bt_divide,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->bt_multiply,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->bt_plus_minus,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->bt_sqrt,SIGNAL(clicked()), this, SLOT(operations()));

}

CalcWindow::~CalcWindow()
{
    delete ui;
}

void CalcWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double current_Value = (ui->calc_result->text()).toDouble();
    if(QString::number(current_Value, 'g', 16).length() < 16)
    {
        current_Value = (ui->calc_result->text() + button->text()).toDouble();
    }
    QString value_output = QString::number(current_Value, 'g', 16);

    ui->calc_result->setText(value_output);
}

void CalcWindow::comma_button_click()
{
    if(!(ui->calc_result->text().contains('.')))
    {
        ui->calc_result->setText(ui->calc_result->text() + '.');
    }
}

void CalcWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double current_Value; //= (ui->calc_result->text()).toDouble();
    QString value_output; //= Qstring::number(current_Value, 'g', 16);
    if(button->text() == "+/-")
    {
        current_Value = (ui->calc_result->text()).toDouble() * (-1);
        value_output = QString::number(current_Value, 'g', 16);
        ui->calc_result->setText(value_output);
    } else if(button->text() == '+')
    {

    }
}

void CalcWindow::on_bt_AC_clicked()
{

}


void CalcWindow::on_bt_equal_clicked()
{

}


void CalcWindow::on_bt_backspace_clicked()
{

}

