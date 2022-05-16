#ifndef MEDICINE_WINDOW_H
#define MEDICINE_WINDOW_H

#include <QWidget>

namespace Ui {
class Medicine_Window;
}

class Medicine_Window : public QWidget
{
    Q_OBJECT

public:
    explicit Medicine_Window(QWidget *parent = nullptr);
    ~Medicine_Window();

private slots:
    /**
    * A function to display all medicines with quantity less that or equal to a specific quantity [number]
    */
    void on_check_shortage_clicked();

    /**
    * A function to navigate back to Admin panel window
    */
    void on_back_clicked();

    /**
    * A function to add a medicine in the database,
    *               display operation message,
    *               update medicines table
    */
    void on_add_medicine_clicked();

    /*
    * A function to check whether a medicine is available in the stock or not, where must enter a medicine name
    */
    void on_check_availability_clicked();

    /**
    * A function to update medicines table (get medicines data from DB and display it)
    */
    void on_show_all_stock_clicked();

    /**
    * A function to delete a medicine from the stock in database
    */
    void on_remove_selected_clicked();

private:
    Ui::Medicine_Window *ui;
};

#endif // MEDICINE_WINDOW_H
