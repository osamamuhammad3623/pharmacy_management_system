#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "employee_window/employee_window.h"
#include "medicine_window/medicine_window.h"
#include "admin_panel/admin_panel.h"
#include "supplier_window/supplier_window.h"
#include "pharmacist_profile_window/pharmacist_profile_window.h"
#include "mainwindow.h"
#include "pharmacist_window/pharmacist_window.h"
#include "Class_Definitions.h"


typedef enum{
    GUI_Employees_Window, GUI_Medicine_Stock_Window, GUI_Pharmacist_Profile_Window,
    GUI_Admin_Panel_Window, GUI_Pharmacist_Window, GUI_Login_Window, GUI_Supplier_Window
}Window_Type;

/*
Description: A function to launch a new UI window and hide current active window
               inputs: Window type to be launched, and a pointer to current active window
*/
void launch_new_window(Window_Type type, QWidget* current_window);

#endif // NAVIGATION_H
