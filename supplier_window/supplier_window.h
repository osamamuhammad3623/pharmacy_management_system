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

private:
    Ui::supplier_window *ui;
};

#endif // SUPPLIER_WINDOW_H
