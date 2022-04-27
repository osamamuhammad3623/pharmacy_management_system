#include "pharmacist_window.h"
#include "navigation.h"
#include "ui_pharmacist_window.h"

pharmacist_window::pharmacist_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pharmacist_window)
{
    ui->setupUi(this);
}

pharmacist_window::~pharmacist_window()
{
    delete ui;
}

void pharmacist_window::on_logout_clicked()
{
    launch_new_window(Login_Window, this);
}

