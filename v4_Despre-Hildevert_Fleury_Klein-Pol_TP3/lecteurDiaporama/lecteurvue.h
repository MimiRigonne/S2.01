#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QObject>
#include <QShortcut>
#include "aproposde.h"


QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

#include <QTimer>

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
    QTimer* timer;
    bool diapoAutoEnCours = false; // Indique si le lecteur est en mode auto
    bool btnSuivClique=false; //Indique si on à appuyer sur btnSuivant
    unsigned int tpsPasse; //Indique le temps d'affichage passé en mode auto

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
    void btnSuivantClique(); // Indique que le bouton Suivant a été cliqué en Mode Auto
    void changerLabelsImg();
    void suivantAuto();

};
#endif // LECTEURVUE_H



