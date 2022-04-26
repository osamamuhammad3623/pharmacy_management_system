#ifndef ADD_MEDICINE_WINDOW_H
#define ADD_MEDICINE_WINDOW_H

#include <QWidget>

namespace Ui {
class add_medicine_window;
}

class add_medicine_window : public QWidget
{
    Q_OBJECT

public:
    explicit add_medicine_window(QWidget *parent = nullptr);
    ~add_medicine_window();

private:
    Ui::add_medicine_window *ui;
};

#endif // ADD_MEDICINE_WINDOW_H
