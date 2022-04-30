#include "pharmacist_window.h"
#include "api.h"
#include "ui_pharmacist_window.h"

Pharmacist_Window::Pharmacist_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pharmacist_Window)
{
    ui->setupUi(this);
}

Pharmacist_Window::~Pharmacist_Window()
{
    delete ui;
}

void Pharmacist_Window::on_check_clicked()
{

}


void Pharmacist_Window::on_logout_clicked()
{
    launch_new_window(GUI_Login_Window, this);
}

