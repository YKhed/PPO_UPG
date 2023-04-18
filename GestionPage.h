#ifndef GESTIONPAGE_H
#define GESTIONPAGE_H

#include <QMainWindow>
#include <Soiree.h>

class GestionPage : public QMainWindow {
    Q_OBJECT

public:
    explicit GestionPage(QWidget *parent = nullptr);

private :
    std::shared_ptr<Soiree> soiree;

private slots:
    void onCreateSoireeClicked();
};




#endif
