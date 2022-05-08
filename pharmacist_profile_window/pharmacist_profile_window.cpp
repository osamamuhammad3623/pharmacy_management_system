#include "pharmacist_profile_window.h"
#include "api.h"
#include "ui_pharmacist_profile_window.h"

Pharmacist current_ph;

pharmacist_profile_window::pharmacist_profile_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pharmacist_profile_window)
{
    ui->setupUi(this);
    current_ph =  get_pharmacist(ph_username);
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
    current_ph.username =  ui->emp_username->toPlainText().toStdString();
    current_ph.password = ui->emp_password->toPlainText().toStdString();
    string result_operation = update_pharmacist(current_ph);
    QMessageBox msg;
    msg.setText(QString::fromStdString(result_operation));
    msg.exec();
    launch_new_window(GUI_Pharmacist_Window,this);
}
