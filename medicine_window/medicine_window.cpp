#include "medicine_window.h"
#include "ui_medicine_window.h"
#include "api.h"

vector<Medicine> med_list;

Medicine_Window::Medicine_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Medicine_Window)
{
    ui->setupUi(this);
    on_show_all_stock_clicked();
    /* add supplier names to Supplier combo-box */
    vector<Supplier> suppliers = get_suppliers();
    for (int i=0; i< suppliers.size();i++){
        ui->md_suppliers->addItem(QString::fromStdString(suppliers[i].name));
    }

    // add fake categories
    for (int i=0; i< 5;i++){
        ui->md_category->addItem("Category " + QString::fromStdString(to_string(i)));
    }
}

Medicine_Window::~Medicine_Window()
{
    delete ui;
}

void Medicine_Window::on_check_shortage_clicked()
{
    vector<Medicine> meds_in_need = check_shortage(ui->max_quantity->value()); /* check for shortage meds */
    ui->shortage_table->setRowCount(meds_in_need.size());

    auto model = ui->shortage_table->model();
    for (int i=0; i< meds_in_need.size(); i++){
        model->setData(model->index(i,0),QString::fromStdString(meds_in_need[i].id));
        model->setData(model->index(i,1),QString::fromStdString(meds_in_need[i].name));
        model->setData(model->index(i,2),meds_in_need[i].quantity);
    }
}


void Medicine_Window::on_back_clicked()
{
    launch_new_window(GUI_Admin_Panel_Window, this);
}


void Medicine_Window::on_add_medicine_clicked()
{
    Medicine md;
    md.id = to_string(ui->md_id->value());
    md.name = ui->md_name->toPlainText().toStdString();
    md.quantity = ui->md_quantity->value();
    md.purchase_price = ui->md_buy_price->value();
    md.sell_price = ui->md_sell_price->value();
    md.category = ui->md_category->currentText().toStdString();
    md.supplier_company = ui->md_suppliers->currentText().toStdString();
    md.expire_date = ui->ex_date->date().toString("dd/MM/yyyy").toStdString();

    string operation_result = insert_medicine(md);
    ui->msg->setText(QString::fromStdString(operation_result));
    on_show_all_stock_clicked();
    /* clear fields after insertion */
    ui->md_id->setValue(0);
    ui->md_quantity->setValue(0);
    ui->md_buy_price->setValue(0);
    ui->md_sell_price->setValue(0);
    ui->md_name->setText("");
}


void Medicine_Window::on_check_availability_clicked()
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


void Medicine_Window::on_show_all_stock_clicked()
{
    med_list = get_medicines();
    ui->shortage_table->setRowCount(med_list.size());

    auto model = ui->shortage_table->model();
    for (int i=0; i< med_list.size(); i++){
        model->setData(model->index(i,0),QString::fromStdString(med_list[i].id));
        model->setData(model->index(i,1),QString::fromStdString(med_list[i].name));
        model->setData(model->index(i,2),(med_list[i].quantity));
    }

}


void Medicine_Window::on_remove_selected_clicked()
{
    vector<Medicine> meds_list = get_medicines(); /* updating table */
    string operation_result;

    /* iterating on rows and check which one that's selected */
    for (int i=0; i< ui->shortage_table->rowCount(); i++){

        if (ui->shortage_table->item(i,0)->isSelected()){

            operation_result = delete_medicine(meds_list[i].id);
            ui->msg->setText(QString::fromStdString(operation_result));
            on_show_all_stock_clicked();
            return;
        }
    }

}

