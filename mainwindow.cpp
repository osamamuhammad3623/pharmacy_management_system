#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "navigation.h"
#include <iostream>
using namespace std;

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
    string user = ui->username->toPlainText().toStdString();
    if (user == "osama"){
        launch_new_window(Admin_Panel_Window, this);
    }else{
        launch_new_window(Pharmacist_Window, this);
    }

}

