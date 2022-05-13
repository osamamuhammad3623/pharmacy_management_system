#include "pharmacist_window.h"
#include "ui_pharmacist_window.h"
#include "api.h"
#include "QDebug"

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
    qDebug() << ui->total_table->item(0,0)->text();
    //update_medicine(, 5);
}


void Pharmacist_window::on_add_medicine_clicked()
{
    Medicine md;
    md.name = ui->md_name->toPlainText().toStdString();
    md.quantity = ui->md_quantity->value();

    bool found= medicine_available(md.name, md.quantity);
    if (found){
        // medicine is available
        double p = get_medicine_price(md.name);
        int current_invoice_size = ui->total_table->rowCount();
        ui->total_table->setRowCount(current_invoice_size+1);
        auto model = ui->total_table->model();
        model->setData(model->index(current_invoice_size,0), QString::fromStdString(md.name));
        model->setData(model->index(current_invoice_size,1), md.quantity);
        model->setData(model->index(current_invoice_size,2), md.quantity*p);

    }else {
        // medicine not available
        QMessageBox msg;
        QString m = "Medicine not found or quantity is not enough!";
        msg.setText(m);
        msg.exec();
    }

    ui->md_name->setText("");
    ui->md_quantity->setValue(0);
}


void Pharmacist_window::on_clear_invoice_clicked()
{
    ui->total_table->clearContents();
    ui->total_table->setRowCount(0);
}

