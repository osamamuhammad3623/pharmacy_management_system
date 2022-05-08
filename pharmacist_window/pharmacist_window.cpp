#include "pharmacist_window.h"
#include "api.h"
#include "QMessageBox"
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
    launch_new_window(GUI_Login_Window,this);
}

void Pharmacist_Window::on_add_medicine_clicked()
{

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

}


void Pharmacist_Window::on_clear_table_clicked()
{
    ui->total_table->clearContents();
}


void Pharmacist_Window::on_check_availability_clicked()
{
    bool found = medicine_available(ui->med_check_name->text().toStdString());
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

