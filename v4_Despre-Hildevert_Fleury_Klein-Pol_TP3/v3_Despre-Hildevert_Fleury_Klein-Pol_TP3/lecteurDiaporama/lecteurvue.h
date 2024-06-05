#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QObject>
#include <QShortcut>
#include "aproposde.h"


QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class Lecteur;
class Diaporama;

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();
    QShortcut *quitShortcut;
    QShortcut *AProposShortcut;


private:
    Ui::LecteurVue *ui;
    AProposDe *dlg;
    Lecteur* lecteur;
    Diaporama* diaporama;

public slots:
    void suivant();
    void precedent();
    void lancerDiapo();
    void arreterDiapo();
    void modifierVitesse();
    void chargerDiapo();
    void enleverDiapo();
    void aProposDe();
    void quitter();
    void filtre();

};
#endif // LECTEURVUE_H



