QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AccueilPage.cpp \
    Bataille.cpp \
    BatailleUI.cpp \
    Carte.cpp \
    CreatePartieDialog.cpp \
    CreateSoireeDialog.cpp \
    Deck.cpp \
    GestionPage.cpp \
    Jeu.cpp \
    Joueur.cpp \
    MelangeAleatoire.cpp \
    Partie.cpp \
    PartiePage.cpp \
    Soiree.cpp \
    SoireePage.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    AccueilPage.h \
    Bataille.h \
    BatailleUI.h \
    Carte.h \
    CreatePartieDialog.h \
    CreateSoireeDialog.h \
    Deck.h \
    FormException.h \
    GestionPage.h \
    Jeu.h \
    JeuExterne.h \
    JeuExterneAdaptateur.h \
    JeuFactory.h \
    Joueur.h \
    MelangeAleatoire.h \
    MelangeStrategie.h \
    Partie.h \
    PartiePage.h \
    Soiree.h \
    SoireePage.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    cartes.qrc
