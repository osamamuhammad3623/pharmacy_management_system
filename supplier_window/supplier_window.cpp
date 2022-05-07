#include "supplier_window.h"
#include "ui_supplier_window.h"
#include "api.h"

vector<Supplier> sup_list;

supplier_window::supplier_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::supplier_window)
{
    ui->setupUi(this);
    on_refresh_clicked(); // view list of suppliers
}

supplier_window::~supplier_window()
{
    delete ui;
}

void supplier_window::on_add_sup_clicked()
{
    Supplier sup;
    sup.id = to_string(ui->sup_id->value());
    sup.name = ui->sup_name->toPlainText().toStdString();
    sup.phone = ui->sup_tele->toPlainText().toStdString();
    sup.address = ui->sup_address->toPlainText().toStdString();

    string operation_result;
    if (ui->add_sup->text() == "Add"){
        operation_result = insert_supplier(sup);
    }else if (ui->add_sup->text() == "Update"){
        //operation_result = update_supplier(sup);
        /* set things back to defaults */
        ui->add_sup->setText("Add");
        ui->sup_id->setEnabled(true);
    }

    ui->msg->setText(QString::fromStdString(operation_result));

    // clear fields
    ui->sup_id->setValue(0);
    ui->sup_name->setText("");
    ui->sup_tele->setText("");
    ui->sup_address->setText("");

}


void supplier_window::on_refresh_clicked()
{
    vector<Supplier> sup_list = get_suppliers();
    ui->sup_table->setRowCount(sup_list.size());

    auto model = ui->sup_table->model();
    for (int i=0; i< sup_list.size(); i++){
        model->setData(model->index(i,0),QString::fromStdString(sup_list[i].id));
        model->setData(model->index(i,1),QString::fromStdString(sup_list[i].name));
        model->setData(model->index(i,2),QString::fromStdString(sup_list[i].phone));
    }
}


void supplier_window::on_remove_selected_row_clicked()
{
    sup_list= get_suppliers(); /* updating table */
    string operation_result;

    /* iterating on rows and check which one that's selected */
    for (int i=0; i< ui->sup_table->rowCount(); i++){

        if (ui->sup_table->item(i,0)->isSelected()){
            //operation_result = remove_supplier(sup_list[i].id);
            ui->msg->setText(QString::fromStdString(operation_result));
            break;
        }
    }

    on_refresh_clicked();
}


void supplier_window::on_edit_clicked()
{
    sup_list= get_suppliers(); /* updating table */
    string operation_result;

    /* iterating on rows and check which one that's selected */
    for (int i=0; i< ui->sup_table->rowCount(); i++){

        if (ui->sup_table->item(i,0)->isSelected()){

            /* get selected pharmacist data */
            Supplier selected_sup = sup_list[i];

            /* display data on add employees fields */
            ui->sup_id->setValue(stoi(selected_sup.id));
            ui->sup_id->setEnabled(false); // you can't change ID
            ui->sup_name->setText(QString::fromStdString(selected_sup.name));
            ui->sup_tele->setText(QString::fromStdString(selected_sup.phone));
            ui->sup_address->setText(QString::fromStdString(selected_sup.address));
            ui->add_sup->setText("Update");
        }
    }
}


void supplier_window::on_back_clicked()
{
    launch_new_window(GUI_Admin_Panel_Window, this);
}

