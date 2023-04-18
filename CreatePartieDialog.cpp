#include "CreatePartieDialog.h"
#include "Partie.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>

CreatePartieDialog::CreatePartieDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Créer une partie");

        auto layout = new QFormLayout(this);

    QLabel *nomPartieLabel = new QLabel("Nom de la partie:");
    nomPartieEdit = new QLineEdit;
    layout->addRow(nomPartieLabel, nomPartieEdit);

    QLabel *typeJeuLabel = new QLabel("Type de jeu:");
    typeJeuComboBox = new QComboBox;
    typeJeuComboBox->addItem("Bataille");
    layout->addRow(typeJeuLabel, typeJeuComboBox);

    auto confirmButton = new QPushButton("Confirmer");
    auto cancelButton = new QPushButton("Annuler");
    layout->addRow(confirmButton, cancelButton);

    connect(confirmButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString CreatePartieDialog::getNomPartie() const
{
    return nomPartieEdit->text();
}

int CreatePartieDialog::getTypeJeu() const
{
    return typeJeuComboBox->currentIndex();
}
