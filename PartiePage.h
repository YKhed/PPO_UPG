
#ifndef PARTIEPAGE_H
#define PARTIEPAGE_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <memory>
#include "Partie.h"

class PartiePage : public QWidget  {
    Q_OBJECT

public:
    explicit PartiePage(std::shared_ptr<Partie> partie, QWidget *parent = nullptr);


private slots:
    void onLaunchGameClicked();
    void onQuitPartieClicked();

private:
    std::shared_ptr<Partie> partie;
    QPushButton *launchGameButton;
    QPushButton *quitPartieButton;

    QLabel* carteJoueurLabel;
    QLabel* carteAppLabel;
    QLabel* scoreJoueurLabel;
    QLabel* scoreAppLabel;
};

#endif // PARTIEPAGE_H
