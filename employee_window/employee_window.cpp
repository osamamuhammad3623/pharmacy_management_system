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
    Pharmacist new_emp;
    new_emp.id = ui->emp_id->value();
    new_emp.fname =  ui->emp_fname->toPlainText().toStdString();
    new_emp.lname =  ui->emp_lname->toPlainText().toStdString();
    new_emp.username =  ui->emp_username->toPlainText().toStdString();
    new_emp.password = ui->emp_password->toPlainText().toStdString();
    new_emp.salary = ui->emp_salary->value();
    if (ui->is_admin->isChecked()){
        new_emp.is_admin = 1;
    }

    //insert_pharmacist(new_emp);

    /* clear fields after insertion */
    ui->emp_id->setValue(0);
    ui->emp_fname->setText("");
    ui->emp_lname->setText("");
    ui->emp_username->setText("");
    ui->emp_password->setText("");
    ui->emp_salary->setValue(0);
}


void Employee_Window::on_back_clicked()
{
    launch_new_window(GUI_Admin_Panel_Window, this);
}

