#include "mainwindow.h"
#include "api.h"
#include "QDebug"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    int result = is_admin(ui->username->toPlainText().toStdString(), ui->password->toPlainText().toStdString());
    if (result == 1){
        launch_new_window(GUI_Admin_Panel_Window, this);
    }else if (result == 0){
        g_pharmacist_username = ui->username->toPlainText().toStdString();

        launch_new_window(GUI_Pharmacist_Window, this);
    }else{
        ui->msg->setText("Username is not found!");
    }
}

