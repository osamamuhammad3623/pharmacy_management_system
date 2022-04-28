#include "employee_window.h"
#include "navigation.h"
#include "ui_employee_window.h"

Employee_Window::Employee_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Employee_Window)
{
    ui->setupUi(this);
}

Employee_Window::~Employee_Window()
{
    delete ui;
}

void Employee_Window::on_add_emp_clicked()
{

}


void Employee_Window::on_back_clicked()
{
    launch_new_window(GUI_Admin_Panel_Window, this);
}

