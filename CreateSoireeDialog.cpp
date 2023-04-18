#include "CreateSoireeDialog.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

CreateSoireeDialog::CreateSoireeDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QFormLayout *formLayout = new QFormLayout();
    nomSoireeLineEdit = new QLineEdit(this);
    formLayout->addRow("Nom de la soirée:", nomSoireeLineEdit);
        codeSoireeLineEdit = new QLineEdit(this);
    formLayout->addRow("Code de la soirée:", codeSoireeLineEdit);
        mainLayout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    createButton = new QPushButton("Créer", this);
                   buttonLayout->addWidget(createButton);
    connect(createButton, &QPushButton::clicked, this, &CreateSoireeDialog::onCreateButtonClicked);

    cancelButton = new QPushButton("Annuler", this);
    buttonLayout->addWidget(cancelButton);
    connect(cancelButton, &QPushButton::clicked, this, &CreateSoireeDialog::onCancelButtonClicked);

    mainLayout->addLayout(buttonLayout);
}

QString CreateSoireeDialog::getNomSoiree() const {
    return nomSoireeLineEdit->text();
}

QString CreateSoireeDialog::getCodeSoiree() const {
    return codeSoireeLineEdit->text();
}

void CreateSoireeDialog::onCreateButtonClicked() {
    QDialog::accept();
}

void CreateSoireeDialog::onCancelButtonClicked() {
    QDialog::reject();
}
