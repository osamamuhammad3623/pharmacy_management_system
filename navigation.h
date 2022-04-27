#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "add_employees_window.h"
#include "add_medicine_window.h"
#include "admin_panel.h"
#include "mainwindow.h"
#include "pharmacist_window.h"

typedef enum{
    Employees_Window, Medicine_Stock_Window, Admin_Panel_Window, Pharmacist_Window, Login_Window
}Window_Type;

/*
Description: A function to launch a new UI window and hide current active window
               inputs: Window type to be launched, and a pointer to current active window
*/
void launch_new_window(Window_Type type, QWidget* current_window);

#endif // NAVIGATION_H
