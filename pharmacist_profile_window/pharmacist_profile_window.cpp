#include "pharmacist_profile_window.h"
#include "api.h"
#include "ui_pharmacist_profile_window.h"

pharmacist_profile_window::pharmacist_profile_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pharmacist_profile_window)
{
    ui->setupUi(this);
    Pharmacist current_ph =  get_pharmacist(ph_username);
    ui->emp_id->setValue(stoi(current_ph.id));
    ui->emp_username->setText(QString::fromStdString(current_ph.username));
    ui->emp_password->setText(QString::fromStdString(current_ph.password));
    ui->emp_salary->setValue(current_ph.salary);

    ui->emp_id->setReadOnly(true);
    ui->emp_salary->setReadOnly(true);
}

pharmacist_profile_window::~pharmacist_profile_window()
{
    delete ui;
}

void pharmacist_profile_window::on_save_clicked()
{
    Pharmacist updated_ph;
    updated_ph.id = to_string(ui->emp_id->value());
    updated_ph.username =  ui->emp_username->toPlainText().toStdString();
    ph_username = updated_ph.username;
    updated_ph.password = ui->emp_password->toPlainText().toStdString();

    string result_operation = update_pharmacist_profile(updated_ph);
    ph_username = updated_ph.username;
    QMessageBox msg;
    msg.setText(QString::fromStdString(result_operation));
    msg.exec();
    launch_new_window(GUI_Pharmacist_Window,this);
}

void pharmacist_profile_window::on_save_2_clicked()
{
    launch_new_window(GUI_Pharmacist_Window, this);
}

