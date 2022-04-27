#include "add_employees_window.h"
#include "pharmacist_class.h"
#include "navigation.h"
#include "ui_add_employees_window.h"

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
    Pharmacist new_pharmacist;
    new_pharmacist.name = ui->pharmacist_name->toPlainText();
    new_pharmacist.password = ui->pharmacist_password->toPlainText();
    new_pharmacist.salary = ui->pharmacist_salary->value();

    //insert_pharmacist(new_pharmacist);

    /* clear fields after insertion */
    ui->pharmacist_name->setText("");
    ui->pharmacist_password->setText("");
    ui->pharmacist_salary->setValue(0);
}


void add_employees_window::on_back_clicked()
{
    launch_new_window(Admin_Panel_Window, this);
}

