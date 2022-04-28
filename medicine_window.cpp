#include "medicine_window.h"
#include "ui_medicine_window.h"
#include "navigation.h"

Medicine_Window::Medicine_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Medicine_Window)
{
    ui->setupUi(this);
}

Medicine_Window::~Medicine_Window()
{
    delete ui;
}

void Medicine_Window::on_check_shortage_clicked()
{

}


void Medicine_Window::on_back_clicked()
{
    launch_new_window(GUI_Admin_Panel_Window, this);
}


void Medicine_Window::on_add_medicine_clicked()
{

}

