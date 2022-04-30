#include "admin_panel.h"
#include "ui_admin_panel.h"
#include "api.h"

Admin_Panel::Admin_Panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Panel)
{
    ui->setupUi(this);
}

Admin_Panel::~Admin_Panel()
{
    delete ui;
}

void Admin_Panel::on_logout_clicked()
{
    launch_new_window(GUI_Login_Window, this);
}


void Admin_Panel::on_add_employees_clicked()
{
    launch_new_window(GUI_Employees_Window, this);
}


void Admin_Panel::on_md_stock_clicked()
{
    launch_new_window(GUI_Medicine_Stock_Window, this);
}

