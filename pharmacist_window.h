#ifndef PHARMACIST_WINDOW_H
#define PHARMACIST_WINDOW_H

#include <QWidget>

namespace Ui {
class pharmacist_window;
}

class pharmacist_window : public QWidget
{
    Q_OBJECT

public:
    explicit pharmacist_window(QWidget *parent = nullptr);
    ~pharmacist_window();

private slots:
    void on_logout_clicked();

    void on_check_clicked();

private:
    Ui::pharmacist_window *ui;
};

#endif // PHARMACIST_WINDOW_H
