#include "add_employees_window.h"
#include "Employee_class.h"
#include "navigation.h"
#include "ui_add_employees_window.h"
#include <iostream>
using namespace std;

add_employees_window::add_employees_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_employees_window)
{
    ui->setupUi(this);
}

add_employees_window::~add_employees_window()
{
    delete ui;
}

void add_employees_window::on_add_pharmacist_clicked()
{
    Employee new_emp;
    new_emp.fname =  ui->emp_fname->toPlainText().toStdString();
    new_emp.lname =  ui->emp_lname->toPlainText().toStdString();
    new_emp.username =  ui->emp_username->toPlainText().toStdString();
    new_emp.password = ui->emp_password->toPlainText().toStdString();
    new_emp.salary = ui->emp_salary->value();
    if (ui->is_ph->isChecked()){
        new_emp.is_pharmacist=Pharmacist;
    }

    //insert_pharmacist(new_emp);

    /* clear fields after insertion */
    ui->emp_fname->setText("");
    ui->emp_lname->setText("");
    ui->emp_username->setText("");
    ui->emp_password->setText("");
    ui->emp_salary->setValue(0);
}


void add_employees_window::on_back_clicked()
{
    launch_new_window(Admin_Panel_Window, this);
}

