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
    /* display admin panel window and hide current window */
    launch_employees_window();
    this->hide();
}

void admin_panel::on_md_stock_clicked()
{
    /* display admin panel window and hide current window */
    launch_medicine_window();
    this->hide();
}


void admin_panel::on_logout_clicked()
{
    launch_login_window();
    this->hide();
}

