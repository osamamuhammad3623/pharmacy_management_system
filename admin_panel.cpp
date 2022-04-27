#include "admin_panel.h"
#include "ui_admin_panel.h"
#include "navigation.h"

admin_panel::admin_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_panel)
{
    ui->setupUi(this);
}

admin_panel::~admin_panel()
{
    delete ui;
}

void admin_panel::on_add_employees_clicked()
{
    launch_new_window(Employees_Window, this);
}

void admin_panel::on_md_stock_clicked()
{
    launch_new_window(Medicine_Stock_Window, this);
}

void admin_panel::on_logout_clicked()
{
    launch_new_window(Login_Window, this);
}

