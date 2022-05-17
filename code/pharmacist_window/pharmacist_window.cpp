#include "pharmacist_window.h"
#include "ui_pharmacist_window.h"
#include "api.h"
#include "QDebug"

Pharmacist_window::Pharmacist_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pharmacist_window)
{
    ui->setupUi(this);
    show_available_medicines();
}

Pharmacist_window::~Pharmacist_window()
{
    delete ui;
}


void Pharmacist_window::show_available_medicines(){

    vector<Medicine> med_list = get_medicines();
    ui->med_table->setRowCount(med_list.size());

    auto model = ui->med_table->model();
    for (int i=0; i< med_list.size(); i++){
        model->setData(model->index(i,0),QString::fromStdString(med_list[i].name));
        model->setData(model->index(i,1),(med_list[i].quantity));
        model->setData(model->index(i,2),(med_list[i].sell_price));
    }

}

void Pharmacist_window::on_add_medicine_clicked()
{
    Medicine md;
    md.name = ui->md_name->text().toStdString();
    md.quantity = ui->md_quantity->value();
    bool found= medicine_available(md.name, md.quantity);
    if (found){
        update_medicine(md.name,md.quantity);

    }else {
        // medicine not available
        QMessageBox msg;
        QString m = "Medicine not found or quantity is not enough!";
        msg.setText(m);
        msg.setWindowTitle("Medicine issue");
        msg.exec();
    }

    ui->md_name->setText("");
    ui->md_quantity->setValue(0);
    show_available_medicines();
}

void Pharmacist_window::on_edit_clicked()
{
    launch_new_window(GUI_Pharmacist_Profile_Window, this);
}


void Pharmacist_window::on_check_price_clicked()
{
    double p = get_medicine_price(ui->med_check_name->text().toStdString());
    QMessageBox msg;

    if (p == 0){
        msg.setText("Medicine NOT found!");
    }else{
        msg.setText("Price: " + QString::fromStdString(to_string(p)));
    }
    msg.setIcon(QMessageBox::Information);
    msg.setWindowTitle("Check Price");
    msg.exec();

}


void Pharmacist_window::on_check_availability_clicked()
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


void Pharmacist_window::on_logout_clicked()
{
    launch_new_window(GUI_Login_Window,this);
}


void Pharmacist_window::on_md_quantity_valueChanged(int arg1)
{
    int q = ui->md_quantity->value();
    double p = get_medicine_price(ui->md_name->text().toStdString());
    QString msg = "Total price = " + QString::number(p*q);
    ui->current_price->setText(msg);
}


void Pharmacist_window::on_alternatives_btn_clicked()
{
    string med_name = ui->med_check_name->text().toStdString();
    vector<Medicine> alters = get_alternatives(ui->med_check_name->text().toStdString());

    if (alters.size() == 0){
        ui->alternatives_label->setText("This medicine has no alternatives!");
    }else{
        QString alternative_text = "Alternative medicines are :-\n";
        for(int i=0; i < alters.size(); i++){
            if (alters[i].name == med_name){
                continue;
            }
            alternative_text += "- " + QString::fromStdString(alters[i].name) +
                    " , price = " + QString::number(alters[i].sell_price) + "\n";
        }

        ui->alternatives_label->setText(alternative_text);
    }

}

