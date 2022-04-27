#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "navigation.h"

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
    QString user = ui->username->toPlainText();
    if (user == "osama"){
        launch_admin_window();
    }else{
        launch_pharmacist_window();
    }
    this->hide();

}

