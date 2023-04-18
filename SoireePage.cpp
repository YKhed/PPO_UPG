#include "SoireePage.h"
#include "PartiePage.h"
#include "FormException.h"
#include "CreatePartieDialog.h"
#include "JeuFactory.h"
#include <QVBoxLayout>
#include <QMessageBox>

SoireePage::SoireePage(std::shared_ptr<Soiree> soiree, QWidget *parent) : QDialog(parent), soiree(soiree) {
    setFixedSize(500, 500);
    QVBoxLayout *layout = new QVBoxLayout(this);

    createPartieButton = new QPushButton("Créer Partie", this);
                         layout->addWidget(createPartieButton);
    connect(createPartieButton, &QPushButton::clicked, this, &SoireePage::onCreatePartieClicked);

    quitSoireeButton = new QPushButton("Quitter soirée", this);
                       layout->addWidget(quitSoireeButton);
    connect(quitSoireeButton, &QPushButton::clicked, this, &SoireePage::onQuitSoireeClicked);
                       setLayout(layout);
}

void SoireePage::onCreatePartieClicked() {
    CreatePartieDialog createPartieDialog(this);
    int result = createPartieDialog.exec();
    if (result == QDialog::Accepted) {
        QString nomPartie = createPartieDialog.getNomPartie();


        try {
            if (nomPartie.isEmpty()) {
                throw FormException("Veuillez remplir les champs du formulaire.");
            } else {
                JeuFactory::TypeJeu typeJeu = static_cast<JeuFactory::TypeJeu>(createPartieDialog.getTypeJeu());

                // Utilisez la JeuFactory pour créer un nouveau jeu
                std::unique_ptr<Jeu> jeu = JeuFactory::creerJeu(typeJeu);

                // Créez une nouvelle Partie avec le jeu créé
                auto partie = std::make_shared<Partie>(nomPartie.toStdString(), std::move(jeu));
                // Ajoutez la nouvelle partie à la soirée
                soiree->ajouterPartie(partie);
                qDebug() << partie->getJeu()->getNomJeu();
                // Ouvrez la nouvelle fenêtre PartiePage
                PartiePage *partiePage = new PartiePage(partie, this);
                partiePage->show();
            }
        } catch (const FormException &e) {
            QMessageBox::warning(this, "Erreur", e.what());
        }

    }
}

void SoireePage::onQuitSoireeClicked() {
                       close();
}
SoireePage::~SoireePage() {
    // Vous pouvez ajouter ici du code pour nettoyer les ressources allouées
}
