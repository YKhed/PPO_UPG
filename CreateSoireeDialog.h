
#ifndef CREATESOIREEDIALOG_H
#define CREATESOIREEDIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class CreateSoireeDialog : public QDialog {
    Q_OBJECT

public:
    explicit CreateSoireeDialog(QWidget *parent = nullptr);

    QString getNomSoiree() const;
    QString getCodeSoiree() const;

private:
    QLineEdit *nomSoireeLineEdit;
    QLineEdit *codeSoireeLineEdit;
    QPushButton *createButton;
    QPushButton *cancelButton;

private slots:
    void onCreateButtonClicked();
    void onCancelButtonClicked();
};
#endif // CREATESOIREEDIALOG_H
