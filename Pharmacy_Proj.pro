QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_panel/admin_panel.cpp \
    api.cpp \
    employee_window/employee_window.cpp \
    main.cpp \
    mainwindow.cpp \
    medicine_window/medicine_window.cpp \
    navigation.cpp \
    pharmacist_window/pharmacist_window.cpp \
    db/shell.c \
    db/sqlite3.c

HEADERS += \
    Class_Definitions.h \
    admin_panel/admin_panel.h \
    api.h \
    employee_window/employee_window.h \
    mainwindow.h \
    medicine_window/medicine_window.h \
    navigation.h \
    pharmacist_window/pharmacist_window.h \
    db/sqlite3.h \
    db/sqlite3ext.h

FORMS += \
    admin_panel/admin_panel.ui \
    employee_window/employee_window.ui \
    mainwindow.ui \
    medicine_window/medicine_window.ui \
    pharmacist_window/pharmacist_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
