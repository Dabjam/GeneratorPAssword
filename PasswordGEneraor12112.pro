QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PasswordGEneraor12112
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    PasswordManager.cpp \
    PasswordGenerator.cpp \
    ClipboardHandler.cpp

HEADERS += \
    mainwindow.h \
    PasswordManager.h \
    PasswordGenerator.h \
    ClipboardHandler.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc \
    styles.qrc

# Подключение OpenSSL
LIBS += -L"C:/msys64/mingw64/lib" -lssl -lcrypto
INCLUDEPATH += "C:/msys64/mingw64/include"
