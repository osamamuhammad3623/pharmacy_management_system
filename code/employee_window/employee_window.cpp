#include "employee_window.h"
#include "api.h"
#include "ui_employee_window.h"

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


void Employee_Window::clear_insertion_fields(){
    ui->emp_id->setValue(0);
    ui->emp_fname->setText("");
    ui->emp_lname->setText("");
    ui->emp_username->setText("");
    ui->emp_password->setText("");
    ui->emp_salary->setValue(0);
    ui->is_admin->setChecked(false);
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

    string operation_result;
    if (ui->add_emp->text() == "Add"){
        operation_result = insert_pharmacist(new_emp);

    }else if (ui->add_emp->text() == "Update"){
        operation_result = update_pharmacist(new_emp);
        /* set things back to defaults */
        ui->add_emp->setText("Add");
        ui->emp_id->setEnabled(true);
    }

    ui->msg->setText(QString::fromStdString(operation_result));

    clear_insertion_fields();
    on_refresh_pharmacist_table_clicked(); /* refresh table */

}


void Employee_Window::on_back_clicked()
{
    launch_new_window(GUI_Admin_Panel_Window,this);
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
    string operation_result;

    /* iterating on rows and check which one that's selected */
    for (int i=0; i< ui->pharmacist_table->rowCount(); i++){

        if (ui->pharmacist_table->item(i,0)->isSelected()){
            int selected_ph = i;
            /* check if the selected user is the last admin alive! */
            if (ph_list[i].is_admin == 0){
                // not admin
                operation_result = remove_pharmacist(ph_list[selected_ph].id);
                ui->msg->setText(QString::fromStdString(operation_result));

            }else{
                int alive_admins=0;
                for (Pharmacist p : ph_list){
                    if (p.is_admin){
                        alive_admins++;
                    }
                }

                if (alive_admins==1){
                    ui->msg->setText("It's the last alive Admin!");
                }else{
                    /* if there're more than one admin, you can delete one successfully */
                    operation_result = remove_pharmacist(ph_list[selected_ph].id);
                    ui->msg->setText(QString::fromStdString(operation_result));
                    break;
                }
            }
        }
    }

    on_refresh_pharmacist_table_clicked();
}


void Employee_Window::on_edit_ph_clicked()
{
    ph_list= get_pharmacists(); /* updating table */
    string operation_result;

    /* iterating on rows and check which one that's selected */
    for (int i=0; i< ui->pharmacist_table->rowCount(); i++){

        if (ui->pharmacist_table->item(i,0)->isSelected()){

            /* display his/her data on add employees fields */
            ui->emp_id->setValue(stoi(ph_list[i].id));
            ui->emp_id->setEnabled(false); // you can't change ID
            ui->emp_fname->setText(QString::fromStdString(ph_list[i].fname));
            ui->emp_lname->setText(QString::fromStdString(ph_list[i].lname));
            ui->emp_username->setText(QString::fromStdString(ph_list[i].username));
            ui->emp_password->setText(QString::fromStdString(ph_list[i].password));
            ui->emp_fname->setText(QString::fromStdString(ph_list[i].fname));
            ui->emp_salary->setValue(ph_list[i].salary);
            if (ph_list[i].is_admin){
                ui->is_admin->setChecked(true);
            }else{
                ui->is_admin->setChecked(false);
            }
            ui->add_emp->setText("Update");
        }
    }
}

