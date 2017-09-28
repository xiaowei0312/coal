# -------------------------------------------------
# Project created by QtCreator 2017-08-29T10:57:34
# -------------------------------------------------
QT += network \
    sql \
    xml
TARGET = CoalQualityDetection
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    dialog_add.cpp \
    dialog_find.cpp \
    dbutil.cpp \
    logutil.cpp \
    data_dependency.cpp \
    dialog_search.cpp \
    smsutil.cpp \
    globalconfig.cpp \
    dialog_login.cpp \
    dialog_setting.cpp \
    user.cpp
HEADERS += mainwindow.h \
    dialog_add.h \
    dialog_find.h \
    dbutil.h \
    logutil.h \
    data_dependency.h \
    dialog_search.h \
    smsutil.h \
    globalconfig.h \
    dialog_login.h \
    dialog_setting.h \
    user.h
FORMS += mainwindow.ui \
    dialog_add.ui \
    dialog_find.ui \
    dialog_search.ui \
    dialog_login.ui \
    dialog_setting.ui
RESOURCES += main.qrc
OTHER_FILES += coal.sql
INCLUDEPATH += $$PWD/include
LIBS += -L$$PWD/lib \
    -lQtSolutions_SOAP-2.6d
