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
    /**
    * A function to update pharmacist username & password
    */
    void on_save_clicked();

    /**
    * A function to navigate back to Pharmacist panel window without applying any updates
    */
    void on_cancel_clicked();

private:
    Ui::pharmacist_profile_window *ui;
};

#endif // PHARMACIST_PROFILE_WINDOW_H
