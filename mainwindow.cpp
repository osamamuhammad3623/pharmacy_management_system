#include "mainwindow.h"
#include "navigation.h"
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
    if (ui->username->toPlainText() == "osama"){
        launch_new_window(GUI_Admin_Panel_Window, this);
    }else{
        launch_new_window(GUI_Pharmacist_Window, this);
    }
}

