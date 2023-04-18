#include "PartiePage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include "BatailleUI.h"

PartiePage::PartiePage(std::shared_ptr<Partie> partie, QWidget *parent)
    : QWidget(parent), partie(partie) {
    setFixedSize(500, 500);
    QVBoxLayout *layout = new QVBoxLayout(this);

    launchGameButton = new QPushButton("Lancer jeu", this);
    layout->addWidget(launchGameButton);
    connect(launchGameButton, &QPushButton::clicked, this, &PartiePage::onLaunchGameClicked);

    quitPartieButton = new QPushButton("Quitter Partie", this);
    layout->addWidget(quitPartieButton);
    connect(quitPartieButton, &QPushButton::clicked, this, &PartiePage::onQuitPartieClicked);
}

void PartiePage::onLaunchGameClicked() {
    qDebug() << "Partie commencée";

    BatailleUI *batailleUI = new BatailleUI(partie, this);
    batailleUI->show();
}

void PartiePage::onQuitPartieClicked() {
    // Ferme la fenêtre PartiePage et revient à SoireePage
    close();
}
