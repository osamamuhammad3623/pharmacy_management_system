#include "employee_window.h"
#include "api.h"
#include "ui_employee_window.h"
#include "QDebug"

vector<Pharmacist> ph_list;

Employee_Window::Employee_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Employee_Window)
{
    ui->setupUi(this);
    on_refresh_pharmacist_table_clicked(); /* show employees table on window start-up */
}

Employee_Window::~Employee_Window()
{
    delete ui;
}

void Employee_Window::on_add_emp_clicked()
{
    Pharmacist new_emp;
    new_emp.id = to_string(ui->emp_id->value());
    new_emp.fname =  ui->emp_fname->toPlainText().toStdString();
    new_emp.lname =  ui->emp_lname->toPlainText().toStdString();
    new_emp.username =  ui->emp_username->toPlainText().toStdString();
    new_emp.password = ui->emp_password->toPlainText().toStdString();
    new_emp.salary = ui->emp_salary->value();
    if (ui->is_admin->isChecked()){
        new_emp.is_admin = 1;
    }

    string operation_result = insert_pharmacist(new_emp);
    ui->msg->setText(QString::fromStdString(operation_result));

    /* clear fields after insertion */
    ui->emp_id->setValue(0);
    ui->emp_fname->setText("");
    ui->emp_lname->setText("");
    ui->emp_username->setText("");
    ui->emp_password->setText("");
    ui->emp_salary->setValue(0);

    on_refresh_pharmacist_table_clicked(); /* refresh table */
}


void Employee_Window::on_back_clicked()
{
    launch_new_window(GUI_Admin_Panel_Window, this);
}


void Employee_Window::on_refresh_pharmacist_table_clicked()
{
    vector<Pharmacist> ph_list = get_pharmacists();
    ui->pharmacist_table->setRowCount(ph_list.size());

    auto model = ui->pharmacist_table->model();
    for (int i=0; i< ph_list.size(); i++){
        model->setData(model->index(i,0),QString::fromStdString(ph_list[i].id));
        model->setData(model->index(i,1),QString::fromStdString(ph_list[i].fname));
        model->setData(model->index(i,2),QString::fromStdString(ph_list[i].lname));
    }
}


void Employee_Window::on_remove_selected_row_clicked(){
    ph_list= get_pharmacists(); /* updating table */

    /* iterating on rows and check which one that's selected */
    int selected_index;
    for (int i=0; i< ui->pharmacist_table->rowCount(); i++){
        if (ui->pharmacist_table->item(i,0)->isSelected()){
            selected_index=i;
        }
    }

    string operation_result = remove_pharmacist(ph_list[selected_index].id);
    ui->msg->setText(QString::fromStdString(operation_result));

    on_refresh_pharmacist_table_clicked();
}

