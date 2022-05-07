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


void Admin_Panel::on_manage_users_clicked()
{
    launch_new_window(GUI_Employees_Window, this);
}


void Admin_Panel::on_manage_suppliers_clicked()
{
    launch_new_window(GUI_Supplier_Window, this);
}


void Admin_Panel::on_manage_med_clicked()
{
    launch_new_window(GUI_Medicine_Stock_Window, this);
}


void Admin_Panel::on_add_medicine_clicked()
{

}


void Admin_Panel::on_add_medicine_2_clicked()
{

}

