#ifndef ADD_EMPLOYEES_WINDOW_H
#define ADD_EMPLOYEES_WINDOW_H

#include <QWidget>

namespace Ui {
class add_employees_window;
}

class add_employees_window : public QWidget
{
    Q_OBJECT

public:
    explicit add_employees_window(QWidget *parent = nullptr);
    ~add_employees_window();

private:
    Ui::add_employees_window *ui;
};

#endif // ADD_EMPLOYEES_WINDOW_H
