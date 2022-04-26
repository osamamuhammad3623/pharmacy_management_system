#ifndef ADMIN_PANEL_H
#define ADMIN_PANEL_H

#include <QWidget>

namespace Ui {
class admin_panel;
}

class admin_panel : public QWidget
{
    Q_OBJECT

public:
    explicit admin_panel(QWidget *parent = nullptr);
    ~admin_panel();

private:
    Ui::admin_panel *ui;
};

#endif // ADMIN_PANEL_H
