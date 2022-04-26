#include "add_employees_window.h"
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
