#ifndef PHARMACIST_WINDOW_H
#define PHARMACIST_WINDOW_H

#include <QWidget>

namespace Ui {
class Pharmacist_window;
}

class Pharmacist_window : public QWidget
{
    Q_OBJECT

public:
    explicit Pharmacist_window(QWidget *parent = nullptr);
    ~Pharmacist_window();

    void show_available_medicines();

private slots:
    void on_add_medicine_clicked();

    void on_edit_clicked();

    void on_check_price_clicked();

    void on_check_availability_clicked();

    void on_logout_clicked();

    void on_md_quantity_valueChanged(int arg1);

    void on_alternatives_btn_clicked();

private:
    Ui::Pharmacist_window *ui;
};

#endif // PHARMACIST_WINDOW_H
