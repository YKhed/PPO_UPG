
#ifndef SOIREEPAGE_H
#define SOIREEPAGE_H
#include <QDialog>
#include <QPushButton>
#include "Soiree.h"

class SoireePage : public QDialog {
    Q_OBJECT

public:
    explicit SoireePage(std::shared_ptr<Soiree> soiree, QWidget* parent = nullptr);
    ~SoireePage();

private:
    std::shared_ptr<Soiree> soiree;
    QPushButton *createPartieButton;
    QPushButton *quitSoireeButton;

private slots:
    void onCreatePartieClicked();
    void onQuitSoireeClicked();
};
#endif // SOIREEPAGE_H
