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

    /**
    * A function to navigate to users window
    */
    void on_manage_users_clicked();

    /**
    * A function to navigate to suppliers window
    */
    void on_manage_suppliers_clicked();

    /**
    * A function to navigate to medicines window
    */
    void on_manage_med_clicked();

private:
    Ui::Admin_Panel *ui;
};

#endif // ADMIN_PANEL_H
