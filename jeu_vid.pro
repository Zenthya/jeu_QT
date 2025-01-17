QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += multimedia

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    afficheur.cpp \
    arrow.cpp \
    background.cpp \
    conttrolleur.cpp \
    floore.cpp \
    graphic_element.cpp \
    main.cpp \
    map.cpp \
    modele.cpp \
    modifiedscene.cpp \
    monster.cpp \
    player.cpp \
    projetile.cpp \
    screen.cpp \
    wall.cpp \
    weapon.cpp

HEADERS += \
    afficheur.h \
    arrow.h \
    background.h \
    conttrolleur.h \
    floore.h \
    graphic_element.h \
    map.h \
    modele.h \
    modifiedscene.h \
    monster.h \
    player.h \
    projetile.h \
    screen.h \
    wall.h \
    weapon.h

FORMS +=

TRANSLATIONS += \
    jeu_vid_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc
