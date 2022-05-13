#include "pharmacist_window.h"
#include "ui_pharmacist_window.h"
#include "api.h"

Pharmacist_window::Pharmacist_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pharmacist_window)
{
    ui->setupUi(this);
}

Pharmacist_window::~Pharmacist_window()
{
    delete ui;
}

void Pharmacist_window::on_print_invoice_clicked()
{
    update_medicine("med1",18);
}

