#include "BatailleUI.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

BatailleUI::BatailleUI(std::shared_ptr<Partie> partie, QWidget *parent) : QMainWindow(parent), partie(partie) {
    setFixedSize(500, 500);
    qDebug() << partie->getJeu();
    bataille = static_cast<Bataille*>(partie->getJeu());
    qDebug() << bataille;
    QWidget *centralWidget = new QWidget(this);

    carteJoueurLabel = new QLabel(this);
    carteAppLabel = new QLabel(this);
    resultatLabel = new QLabel(this);
    jouerTourButton = new QPushButton("Jouer un tour", this);

    QHBoxLayout *carteLayout = new QHBoxLayout;
    carteLayout->addWidget(carteJoueurLabel);
    carteLayout->addWidget(carteAppLabel);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(carteLayout);
    mainLayout->addWidget(resultatLabel);
    mainLayout->addWidget(jouerTourButton);

    connect(jouerTourButton, &QPushButton::clicked, this, &BatailleUI::onJouerTourClicked);
    carteJoueurLabel->setText("Joueur:" );
    carteAppLabel->setText("App: " );
    resultatLabel->setText("Résultat : ");
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void BatailleUI::onJouerTourClicked() {
    bataille->jouer();
    updateUI();
    if (bataille->getResultatTour() == "L'application a gagné !" || bataille->getResultatTour() == "Le joueur a gagné !") {
        QMessageBox::information(this, "Fin de la partie", bataille->getResultatTour().c_str());
        jouerTourButton->setEnabled(false);
    }
}

void BatailleUI::updateUI() {
    carteJoueurLabel->setText(("Joueur: " + bataille->getCarteJoueur()->toString()).c_str());
    carteAppLabel->setText(("App: " + bataille->getCarteApp()->toString()).c_str());
    resultatLabel->setText(bataille->getResultatTour().c_str());
}
