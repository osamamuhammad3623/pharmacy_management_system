#ifndef EMPLOYEE_WINDOW_H
#define EMPLOYEE_WINDOW_H

#include <QWidget>

namespace Ui {
class Employee_Window;
}

class Employee_Window : public QWidget
{
    Q_OBJECT

public:
    explicit Employee_Window(QWidget *parent = nullptr);
    ~Employee_Window();

private slots:
    void on_add_emp_clicked();

    void on_back_clicked();

    void on_refresh_pharmacist_table_clicked();

    void on_remove_selected_row_clicked();

    void on_edit_ph_clicked();

    void clear_insertion_fields();

private:
    Ui::Employee_Window *ui;
};

#endif // EMPLOYEE_WINDOW_H
