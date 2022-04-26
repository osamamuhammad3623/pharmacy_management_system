#include "add_medicine_window.h"
#include "ui_add_medicine_window.h"

add_medicine_window::add_medicine_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_medicine_window)
{
    ui->setupUi(this);
}

add_medicine_window::~add_medicine_window()
{
    delete ui;
}
