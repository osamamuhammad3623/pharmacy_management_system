#include "admin_panel.h"
#include "ui_admin_panel.h"

admin_panel::admin_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_panel)
{
    ui->setupUi(this);
}

admin_panel::~admin_panel()
{
    delete ui;
}
