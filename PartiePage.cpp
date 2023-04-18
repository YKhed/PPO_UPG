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
    // Lance le jeu en appelant la méthode "jouer" de la classe Jeu
    /* if (auto bataille = dynamic_cast<Bataille*>(partie->getJeu())) {
        // Créez une instance de BatailleConsoleUI et enregistrez-la en tant qu'observateur
        auto batailleConsoleUI = std::make_shared<BatailleConsoleUI>();
        bataille->ajouterObserver(batailleConsoleUI.get());

        // Lancez le jeu en appelant la méthode "jouer" de la classe Jeu
        partie->getJeu()->jouer();

        // Supprimez l'observateur après la fin du jeu
        bataille->supprimerObserver(batailleConsoleUI.get());
    } else {
        // Lancez le jeu en appelant la méthode "jouer" de la classe Jeu
        partie->getJeu()->jouer();
    }*/
    qDebug() << "Partie commencée";

    BatailleUI *batailleUI = new BatailleUI(partie, this);
    //batailleUI->setAttribute(Qt::WA_DeleteOnClose);
    batailleUI->show();
}

void PartiePage::onQuitPartieClicked() {
    // Ferme la fenêtre PartiePage et revient à SoireePage
    close();
}
