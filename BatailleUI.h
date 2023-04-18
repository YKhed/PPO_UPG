
#ifndef BATAILLEUI_H
#define BATAILLEUI_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <memory>
#include "Bataille.h"
#include "Partie.h"

class BatailleUI : public QMainWindow{
    Q_OBJECT

public:
    BatailleUI(std::shared_ptr<Partie> partie, QWidget *parent = nullptr);

private slots:
    void onJouerTourClicked();

private:
    std::shared_ptr<Partie> partie;
    QLabel *carteJoueurLabel;
    QLabel *carteAppLabel;
    QLabel *resultatLabel;
    QPushButton *jouerTourButton;
    Bataille* bataille;

    void updateUI();
};

#endif // BATAILLEUI_H
