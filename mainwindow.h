#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


/*****************************************
 *  Login Window
 * ***************************************/


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
    * A function to login to the user main panel according to its role [Admin or Pharmacist]
    *   - Take user-input credentials and check in the database
    *   - if it's a pharmacist credentials, navigate to a Pharmacist panel
    *   - if it's an admin credentials, navigate to an Admin panel
    *   - otherwise, display that credentials are invalid
    */
    void on_login_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
