#include "calcwindow.h"
#include "./ui_calcwindow.h"
#include "cmath"

static bool equaled;
double prev_value;
static bool exist_prev_value;

CalcWindow::CalcWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalcWindow)
{
    ui->setupUi(this);

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
    connect(ui->bt_plus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->bt_minus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->bt_divide,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->bt_multiply,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->bt_sqrt,SIGNAL(clicked()), this, SLOT(math_operations()));

    exist_prev_value = false;
    equaled = false;
}

CalcWindow::~CalcWindow()
{
    delete ui;
}

void CalcWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double current_value;
    prev_value;
    if(!equaled)
    {
    current_value = (ui->calc_result->text()).toDouble();
        if(QString::number(current_value, 'g', 16).length() < 16)
        {
            current_value = (ui->calc_result->text() + button->text()).toDouble();
        }
        QString value_output = QString::number(current_value, 'g', 16);

        ui->calc_result->setText(value_output);
    } else {
        prev_value = (ui->calc_result->text()).toDouble();
        QString value_output = QString::number(prev_value, 'g', 16);
        ui->calc_result->setText(button->text());
        equaled = false;
    }
}

void CalcWindow::comma_button_click()
{
    if(!(ui->calc_result->text().contains('.')))
    {
        ui->calc_result->setText(ui->calc_result->text() + '.');
    }
}

void CalcWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    double current_value = (ui->calc_result->text()).toDouble();
    QString value_output;
    double inter_value;
    // if(current_value != 0)
    // {
    //     prev_value = current_value;
    //     exist_prev_value = true;
    //     ui->calc_result->setText("0");
    //     value_output = QString::number(prev_value, 'g', 16);
    //     ui->prev_result->setText(value_output);
    //     ui->calc_symbol->setText(button->text());
    // } else {
    //     ui->calc_result->setText("0");
    //     value_output = QString::number(prev_value, 'g', 16);
    //     ui->prev_result->setText(value_output);
    //     ui->calc_symbol->setText(button->text());
    // }
    qDebug() << "Cur:" << ui->calc_result->text() << " prev:" << prev_value;
    if(button->text() == "+")
    {
        qDebug() << button->text();
        if(exist_prev_value)
        {
            inter_value = current_value;
            current_value = prev_value + current_value;
            prev_value = current_value;
            value_output = QString::number(prev_value, 'g', 16);
            ui->prev_result->setText(value_output);
            ui->calc_symbol->setText(button->text());
            value_output = QString::number(current_value, 'g', 16);
            equaled = true;
            ui->calc_result->setText(value_output);
        } else
        {
            prev_value = current_value;
            exist_prev_value = true;
            value_output = QString::number(prev_value, 'g', 16);
            ui->prev_result->setText(value_output);
            ui->calc_symbol->setText(button->text());
            ui->calc_result->setText("0");
        }
    } else if(button->text() == "-")
    {
        qDebug() << button->text();
        if(exist_prev_value)
        {
            inter_value = current_value;
            current_value = prev_value - current_value;
            prev_value = current_value;
            value_output = QString::number(prev_value, 'g', 16);
            ui->prev_result->setText(value_output);
            ui->calc_symbol->setText(button->text());
            value_output = QString::number(current_value, 'g', 16);
            equaled = true;
            ui->calc_result->setText(value_output);
        } else
        {
            prev_value = current_value;
            exist_prev_value = true;
            value_output = QString::number(prev_value, 'g', 16);
            ui->prev_result->setText(value_output);
            ui->calc_symbol->setText(button->text());
            ui->calc_result->setText("0");
        }
    } else if(button->text() == "/")
    {
        qDebug() << button->text();
        if(exist_prev_value && current_value != 0)
        {
            inter_value = current_value;
            current_value = prev_value / current_value;
            prev_value = inter_value;
            value_output = QString::number(prev_value, 'g', 16);
            ui->prev_result->setText(value_output);
            ui->calc_symbol->setText(button->text());
            value_output = QString::number(current_value, 'g', 16);
            equaled = true;
            ui->calc_result->setText(value_output);
        } else if (exist_prev_value && current_value == 0)
        {
            ui->calc_result->setText("Cannot divide by zero");
        } else {
            prev_value = current_value;
            exist_prev_value = true;
            value_output = QString::number(prev_value, 'g', 16);
            ui->prev_result->setText(value_output);
            ui->calc_symbol->setText(button->text());
            ui->calc_result->setText("0");
        }
    } else if(button->text() == "x")
    {
        qDebug() << button->text();
        if(exist_prev_value)
        {
            inter_value = current_value;
            current_value = prev_value * current_value;
            prev_value = current_value;
            value_output = QString::number(prev_value, 'g', 16);
            ui->prev_result->setText(value_output);
            ui->calc_symbol->setText(button->text());
            value_output = QString::number(current_value, 'g', 16);
            equaled = true;
            ui->calc_result->setText(value_output);
        } else
        {
            prev_value = current_value;
            exist_prev_value = true;
            value_output = QString::number(prev_value, 'g', 16);
            ui->prev_result->setText(value_output);
            ui->calc_symbol->setText(button->text());
            ui->calc_result->setText("0");
        }
    } else if(button->text() == "√")
    {
        qDebug() << button->text();
        value_output = QString::number(current_value, 'g', 16);
        ui->prev_result->setText(value_output);
        inter_value = std::sqrt(current_value);
        value_output = QString::number(inter_value, 'g', 16);
        ui->calc_symbol->setText(button->text());
        ui->calc_result->setText(value_output);
        equaled = true;
    }
}

void CalcWindow::on_bt_AC_clicked()
{

}


void CalcWindow::on_bt_equal_clicked()
{
    qDebug() << "Cur:" << ui->calc_result->text() << " prev:" << prev_value;
    qDebug() << "=";
    double current_value = (ui->calc_result->text()).toDouble();
    QString value_output;
    current_value += prev_value;
    value_output = QString::number(current_value, 'g', 16);
    ui->calc_symbol->setText("=");
    ui->calc_result->setText(value_output);
    value_output = QString::number(prev_value, 'g', 16);
    ui->prev_result->setText(value_output);
}


void CalcWindow::on_bt_backspace_clicked()
{

}


void CalcWindow::on_bt_plus_minus_clicked()
{
    double current_value; //= (ui->calc_result->text()).toDouble();
    QString value_output; //= Qstring::number(current_Value, 'g', 16);
    current_value = (ui->calc_result->text()).toDouble() * (-1);
    value_output = QString::number(current_value, 'g', 16);
    ui->calc_result->setText(value_output);
}

