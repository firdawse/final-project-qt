QT        += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cell.cpp \
    dialog.cpp \
    g1.cpp \
    g2.cpp \
    g3.cpp \
    game.cpp \
    game1.cpp \
    game2.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    cell.h \
    dialog.h \
    g1.h \
    g2.h \
    g3.h \
    game.h \
    game1.h \
    game2.h \
    mainwindow.h \
    state.h

FORMS += \
    dialog.ui \
    g1.ui \
    g2.ui \
    g3.ui \
    game1.ui \
    game2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

DISTFILES += \
    back.png \
    bomb.png \
    box.png \
    classic.mp3 \
    click.mp3 \
    dead.png \
    flag.png \
    lost.mp3 \
    mute.png \
    smile.png \
    sound.png \
    w.mp3 \
    win.mp3
