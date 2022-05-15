#include "mainwindow.h"
#include "api.h"
#include "QDebug"
#include "ui_mainwindow.h"

string ph_username;
sqlite3* db;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sqlite3_open("Pharmacy.db", &db);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{

    int result = is_admin(ui->username->text().toStdString(), ui->password->text().toStdString());

    if (result == 1){
        launch_new_window(GUI_Admin_Panel_Window, this);
    }else if (result == 0){
        ph_username= ui->username->text().toStdString();
        launch_new_window(GUI_Pharmacist_Window, this);
    }else{
        ui->msg->setText("Username is not found!");
    }
}

