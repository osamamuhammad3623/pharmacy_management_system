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
    /**
    * A function to add/update a user [admin/employee] in the database,
    *               display operation message,
    *               update users table
    */
    void on_add_emp_clicked();

    /**
    * A function to navigate back to Admin panel window
    */
    void on_back_clicked();

    /**
    * A function to update users table (get users data from DB and display it)
    */
    void on_refresh_pharmacist_table_clicked();

    /**
    * A function to remove a user.
    *   - If user is a pharmacist, it's deleted directly
    *   - If user is an admin, if he/she is the last admin, it can NOT be deleted, otherwise it's OK to delete.
    */
    void on_remove_selected_row_clicked();

    /**
    * A function to update a user data
    */
    void on_edit_ph_clicked();

    /**
    * A function to clear input fields [i.e. text-inputs and spin-boxes]
    */
    void clear_insertion_fields();

private:
    Ui::Employee_Window *ui;
};

#endif // EMPLOYEE_WINDOW_H
