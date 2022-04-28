#ifndef PHARMACIST_WINDOW_H
#define PHARMACIST_WINDOW_H

#include <QWidget>

namespace Ui {
class Pharmacist_Window;
}

class Pharmacist_Window : public QWidget
{
    Q_OBJECT

public:
    explicit Pharmacist_Window(QWidget *parent = nullptr);
    ~Pharmacist_Window();

private slots:
    void on_check_clicked();

    void on_logout_clicked();

private:
    Ui::Pharmacist_Window *ui;
};

#endif // PHARMACIST_WINDOW_H
