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

private slots:
    void on_print_invoice_clicked();

private:
    Ui::Pharmacist_window *ui;
};

#endif // PHARMACIST_WINDOW_H
