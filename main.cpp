
#include "AccueilPage.h"
#include "GestionPage.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AccueilPage accueilPage;
    GestionPage gestionPage;

    QObject::connect(&accueilPage, &AccueilPage::continuerEnTantQuInvite, [&]() {
        accueilPage.hide();
        gestionPage.show();
    });

    accueilPage.show();
    return a.exec();
}
