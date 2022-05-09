#include "pharmacist_window.h"
#include "api.h"
#include "QMessageBox"
#include "ui_pharmacist_window.h"
#include <fstream>
#include <iostream>
using namespace std;

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

void Pharmacist_Window::on_logout_clicked()
{
    launch_new_window(GUI_Login_Window,this);
}

void Pharmacist_Window::on_add_medicine_clicked()
{
    Medicine md;
    md.id = ui->md_id->text().toStdString();
    md.name= ui->md_name->toPlainText().toStdString();
    md.quantity = ui->md_quantity->value();
    md.date_added = ui->md_date->date().toString("dd/MM/yyyy").toStdString();

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

    ui->md_id->setValue(1);
    ui->md_name->setText("");
    ui->md_quantity->setValue(0);
}

void Pharmacist_Window::on_check_price_clicked()
{
    double p = get_medicine_price(ui->med_check_name->text().toStdString());
    QMessageBox msg;

    if (p == 0){
        msg.setText("Medicine NOT found!");
    }else{
        msg.setText("Price: " + QString::fromStdString(to_string(p)));
    }
    msg.setIcon(QMessageBox::Information);
    msg.setWindowTitle("Check availability");
    msg.exec();
}


void Pharmacist_Window::on_edit_clicked()
{
    launch_new_window(GUI_Pharmacist_Profile_Window, this);
}


void Pharmacist_Window::on_print_clicked()
{
    ofstream file("invoice.txt");
    QString name; int q, p;
    for (int i=0; i< ui->total_table->rowCount(); i++){
        name = ui->total_table->model()->data(ui->total_table->model()->index(i,0)).toString();
        q = ui->total_table->model()->data(ui->total_table->model()->index(i,1)).toInt();
        p = ui->total_table->model()->data(ui->total_table->model()->index(i,2)).toInt();

        // update medicine quantity in DB
        update_sold_medicine(name.toStdString(), q);

        // print
        file << "Medicine " << (i+1) << ":-\n";
        file << "   Name: " << name.toStdString() << ",\n";
        file << "   Quantity: " << q << ",\n";
        file << "   Price: " << p << ",\n\n";
    }
    QMessageBox msg;
    msg.setText("Invoice printed!");
    msg.exec();
}


void Pharmacist_Window::on_clear_table_clicked()
{
    ui->total_table->clearContents();
    ui->total_table->setRowCount(0);
}


void Pharmacist_Window::on_check_availability_clicked()
{
    bool found = medicine_available(ui->med_check_name->text().toStdString(),0);
    QMessageBox msg;
    if (found){
        msg.setText("Medicine is available!");
    }else{
        msg.setText("Medicine is NOT available!");
    }

    msg.setIcon(QMessageBox::Information);
    msg.setWindowTitle("Check availability");
    msg.exec();
}

