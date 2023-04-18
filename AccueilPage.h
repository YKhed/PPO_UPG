#ifndef ACCUEILPAGE_H
#define ACCUEILPAGE_H

#include <QMainWindow>

class AccueilPage : public QMainWindow {
    Q_OBJECT

public:
    explicit AccueilPage(QWidget *parent = nullptr);

signals:
    void continuerEnTantQuInvite();
};

#endif
