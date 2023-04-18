#include "GestionPage.h"
#include "CreateSoireeDialog.h"
#include "FormException.h"
#include <QMessageBox>
#include "SoireePage.h"

#include <QVBoxLayout>
#include <QPushButton>

GestionPage::GestionPage(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(500, 500);
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *creerSoiree = new QPushButton("Créer une soirée", this);
    QPushButton *rejoindreSoiree = new QPushButton("Rejoindre une soirée", this);
    QPushButton *options = new QPushButton("Options", this);
    QPushButton *quitter = new QPushButton("Quitter", this);

    layout->addWidget(creerSoiree);
    layout->addWidget(rejoindreSoiree);
    layout->addWidget(options);
    layout->addWidget(quitter);

    connect(quitter, &QPushButton::clicked, this, &QMainWindow::close);
    connect(creerSoiree, &QPushButton::clicked, this, &GestionPage::onCreateSoireeClicked);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void GestionPage::onCreateSoireeClicked() {
    qDebug() << "onCreateSoireeClicked() called"; // Ajoutez cette ligne
    CreateSoireeDialog createSoireeDialog(this);
    int result = createSoireeDialog.exec();

    if (result == QDialog::Accepted) {
        QString nomSoiree = createSoireeDialog.getNomSoiree();
        QString codeSoiree = createSoireeDialog.getCodeSoiree();

        try {
            if (nomSoiree.isEmpty() || codeSoiree.isEmpty()) {
                throw FormException("Veuillez remplir les champs du formulaire.");
            } else {
                std::shared_ptr<Soiree> soiree = std::make_shared<Soiree>(nomSoiree, codeSoiree);

                SoireePage* soireePage = new SoireePage(soiree, this);
                qDebug() << "SoireePage created";
                int result = soireePage->exec(); // Affichez la fenêtre modale et récupérez le résultat

                if (result == QDialog::Accepted) {
                    this->hide(); // Cachez la fenêtre GestionPage si SoireePage est fermée avec succès
                }
                qDebug() << "SoireePage shown";
            }
        } catch (const FormException &e) {
            QMessageBox::warning(this, "Erreur", e.what());
        }
    }
}
