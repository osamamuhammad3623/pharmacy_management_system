#ifndef PHARMACIST_PROFILE_WINDOW_H
#define PHARMACIST_PROFILE_WINDOW_H

#include <QWidget>

namespace Ui {
class pharmacist_profile_window;
}

class pharmacist_profile_window : public QWidget
{
    Q_OBJECT

public:
    explicit pharmacist_profile_window(QWidget *parent = nullptr);
    ~pharmacist_profile_window();

private slots:
    void on_save_clicked();

private:
    Ui::pharmacist_profile_window *ui;
};

#endif // PHARMACIST_PROFILE_WINDOW_H
