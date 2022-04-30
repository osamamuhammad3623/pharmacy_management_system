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
    void on_check_shortage_clicked();

    void on_back_clicked();

    void on_add_medicine_clicked();

    void on_add_sup_clicked();

private:
    Ui::Medicine_Window *ui;
};

#endif // MEDICINE_WINDOW_H
