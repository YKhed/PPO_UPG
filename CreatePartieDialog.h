
#ifndef CREATEPARTIEDIALOG_H
#define CREATEPARTIEDIALOG_H
#include <QDialog>

#include <QDialog>

class QLineEdit;
class QComboBox;

class CreatePartieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePartieDialog(QWidget *parent = nullptr);

    QString getNomPartie() const;
    int getTypeJeu() const;

private:
    QLineEdit *nomPartieEdit;
    QComboBox *typeJeuComboBox;
};
#endif // CREATEPARTIEDIALOG_H
