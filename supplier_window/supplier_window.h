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
    void on_add_sup_clicked();

    void on_refresh_clicked();

    void on_remove_selected_row_clicked();

    void on_edit_clicked();

    void on_back_clicked();

private:
    Ui::supplier_window *ui;
};

#endif // SUPPLIER_WINDOW_H
