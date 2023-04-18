#include "AccueilPage.h"

#include <QVBoxLayout>
#include <QPushButton>

AccueilPage::AccueilPage(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(500, 500);
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *creerCompte = new QPushButton("Créer un compte", this);
        QPushButton *seConnecter = new QPushButton("Se connecter", this);
    QPushButton *continuerEnTantQuInvite = new QPushButton("Continuer en tant qu'invité", this);

                                           layout->addWidget(creerCompte);
    layout->addWidget(seConnecter);
    layout->addWidget(continuerEnTantQuInvite);

    connect(continuerEnTantQuInvite, &QPushButton::clicked, this, &AccueilPage::continuerEnTantQuInvite);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}
