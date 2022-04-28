#include "add_medicine_window.h"
#include "Medicine_class.h"
#include "navigation.h"
#include "supplier_class.h"
#include <vector>
#include "ui_add_medicine_window.h"

add_medicine_window::add_medicine_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_medicine_window)
{
    ui->setupUi(this);
    /* add supplier names to Supplier combo-box */
//    vector<Supplier> suppliers; // = get_suppliers;
//    for (int i=0; i< suppliers.size();i++){
//        ui->md_suppliers->addItem(QString::fromStdString(suppliers[i].name));
//    }
}

add_medicine_window::~add_medicine_window()
{
    delete ui;
}


void add_medicine_window::on_back_clicked()
{
    launch_new_window(Admin_Panel_Window, this);
}


void add_medicine_window::on_pushButton_clicked()
{
    Medicine md;
    md.id = ui->md_id->value();
    md.name = ui->md_name->toPlainText().toStdString();
    md.quantity = ui->md_quantity->value();
    md.buy_price = ui->md_buy_price->value();
    md.sell_price = ui->md_sell_price->value();
    md.category = ui->md_category->currentText().toStdString();
    md.supplier_company = ui->md_suppliers->currentText().toStdString();

    // insert_medicine(md);
}
