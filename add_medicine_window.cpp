#include "add_medicine_window.h"
#include "medicine_class.h"
#include "navigation.h"
#include "ui_add_medicine_window.h"

add_medicine_window::add_medicine_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_medicine_window)
{
    ui->setupUi(this);
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
    md.name = ui->md_name->toPlainText();
    md.quantity = ui->md_quantity->value();
    md.buy_price = ui->md_buy_price->value();
    md.sell_price = ui->md_sell_price->value();
    md.category = ui->md_category->currentText();
    md.supplier_company = ui->md_supplier_company->toPlainText();

    // insert_medicine(md);
}

