#include "medicine_window.h"
#include "ui_medicine_window.h"
#include "navigation.h"

Medicine_Window::Medicine_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Medicine_Window)
{
    ui->setupUi(this);
    /* add supplier names to Supplier combo-box */
//    vector<Supplier> suppliers; // = get_suppliers;
//    for (int i=0; i< suppliers.size();i++){
//        ui->md_suppliers->addItem(QString::fromStdString(suppliers[i].name));
//    }
}

Medicine_Window::~Medicine_Window()
{
    delete ui;
}

void Medicine_Window::on_check_shortage_clicked()
{

}


void Medicine_Window::on_back_clicked()
{
    launch_new_window(GUI_Admin_Panel_Window, this);
}


void Medicine_Window::on_add_medicine_clicked()
{
    Medicine md;
    md.id = ui->md_id->value();
    md.name = ui->md_name->toPlainText().toStdString();
    md.quantity = ui->md_quantity->value();
    md.purchase_price = ui->md_buy_price->value();
    md.sell_price = ui->md_sell_price->value();
    md.category = ui->md_category->currentText().toStdString();
    md.supplier_company = ui->md_suppliers->currentText().toStdString();

    // insert

    /* clear fields after insertion */
    ui->md_id->setValue(0);
    ui->md_quantity->setValue(0);
    ui->md_buy_price->setValue(0);
    ui->md_sell_price->setValue(0);
    ui->md_name->setText("");
}

