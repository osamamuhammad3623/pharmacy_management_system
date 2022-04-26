QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_employees_window.cpp \
    add_medicine_window.cpp \
    admin_panel.cpp \
    main.cpp \
    mainwindow.cpp \
    pharmacist_window.cpp

HEADERS += \
    add_employees_window.h \
    add_medicine_window.h \
    admin_panel.h \
    mainwindow.h \
    pharmacist_window.h

FORMS += \
    add_employees_window.ui \
    add_medicine_window.ui \
    admin_panel.ui \
    mainwindow.ui \
    pharmacist_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
