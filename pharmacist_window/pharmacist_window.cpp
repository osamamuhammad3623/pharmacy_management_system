#include "pharmacist_window.h"
#include "api.h"
#include "QMessageBox"
#include "ui_pharmacist_window.h"

Pharmacist_Window::Pharmacist_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pharmacist_Window)
{
    ui->setupUi(this);
    Pharmacist current_ph; // get_current_ph(g_pharmacist_username)
    ui->emp_id->setValue(stoi(current_ph.id));
    ui->emp_username->setText(QString::fromStdString(current_ph.username));
    ui->emp_password->setText(QString::fromStdString(current_ph.password));

    ui->emp_id->setReadOnly(true);
    ui->emp_username->setReadOnly(true);
    ui->emp_password->setReadOnly(true);
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

void Pharmacist_Window::on_check_availability_clicked()
{
    QMessageBox msg;
    msg.setText("");
    msg.setIcon(QMessageBox::Information);
    msg.setWindowTitle("Check availability");
    msg.exec();

}


void Pharmacist_Window::on_add_medicine_clicked()
{

}


void Pharmacist_Window::on_check_price_clicked()
{

}


void Pharmacist_Window::on_edit_clicked()
{
    if (ui->edit->text() == "Edit profile"){
        ui->emp_username->setReadOnly(false);
        ui->emp_password->setReadOnly(false);

        ui->edit->setText("Update");
    }else{
        Pharmacist updated_ph;
        updated_ph.username = ui->emp_username->toPlainText().toStdString();
        updated_ph.password = ui->emp_password->toPlainText().toStdString();
        // update_ph_profile(ph)
    }

}


void Pharmacist_Window::on_print_clicked()
{

}


void Pharmacist_Window::on_clear_table_clicked()
{
    ui->total_table->clearContents();
}

