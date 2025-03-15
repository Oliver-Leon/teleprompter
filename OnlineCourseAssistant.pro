QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/dropedit.cpp \
    src/main.cpp \
    src/widget.cpp \
    src/windowmanagement.cpp \
    src/teleprompter.cpp

HEADERS += \
    include/dropedit.h \
    include/widget.h \
    include/windowmanagement.h \
    include/teleprompter.h

FORMS += \
    widget.ui

INCLUDEPATH += include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
