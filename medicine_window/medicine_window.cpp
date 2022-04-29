#include "medicine_window.h"
#include "ui_medicine_window.h"
#include "api.h"

Medicine_Window::Medicine_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Medicine_Window)
{
    ui->setupUi(this);
    /* add supplier names to Supplier combo-box */
    vector<Supplier> suppliers = get_suppliers();
    for (int i=0; i< suppliers.size();i++){
        ui->md_suppliers->addItem(QString::fromStdString(suppliers[i].name));
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

    string operation_result = insert_medicine(md);
    ui->msg->setText(QString::fromStdString(operation_result));

    /* clear fields after insertion */
    ui->md_id->setValue(0);
    ui->md_quantity->setValue(0);
    ui->md_buy_price->setValue(0);
    ui->md_sell_price->setValue(0);
    ui->md_name->setText("");
}

