#ifndef ADMIN_PANEL_H
#define ADMIN_PANEL_H

#include <QWidget>

namespace Ui {
class Admin_Panel;
}

class Admin_Panel : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Panel(QWidget *parent = nullptr);
    ~Admin_Panel();

private slots:
    void on_logout_clicked();

    void on_add_employees_clicked();

    void on_md_stock_clicked();

private:
    Ui::Admin_Panel *ui;
};

#endif // ADMIN_PANEL_H
