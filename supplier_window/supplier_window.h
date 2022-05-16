#ifndef SUPPLIER_WINDOW_H
#define SUPPLIER_WINDOW_H

#include <QWidget>

namespace Ui {
class supplier_window;
}

class supplier_window : public QWidget
{
    Q_OBJECT

public:
    explicit supplier_window(QWidget *parent = nullptr);
    ~supplier_window();

private slots:

    /**
    * A function to add/update a supplier in the database,
    *               display operation message,
    *               update suppliers table
    */
    void on_add_sup_clicked();

    /**
    * A function to update suppliers table (get suppliers data from DB and display it)
    */
    void on_refresh_clicked();

    /**
    * A function to delete a supplier from the stock in database
    */
    void on_remove_selected_row_clicked();

    /**
    * A function to update a supplier data
    */
    void on_edit_clicked();

    /**
    * A function to navigate back to Admin panel window
    */
    void on_back_clicked();

private:
    Ui::supplier_window *ui;
};

#endif // SUPPLIER_WINDOW_H
