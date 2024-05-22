#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include "presentation.h"

#include <QAction>

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    QObject::connect(ui->btnSuivant,SIGNAL(clicked()),this,SLOT(demandeDiapoSuiv()));
    QObject::connect(ui->btnPrecedent,SIGNAL(clicked()),this,SLOT(demandeDiapoPrec()));
    QObject::connect(ui->btnLancerDiapo,SIGNAL(clicked()),this,SLOT(demandeLancerDiapo()));
    QObject::connect(ui->btnArreterDiapo,SIGNAL(clicked()),this,SLOT(demandeArreterDiapo()));


    QObject::connect(ui->actionAProposDe, SIGNAL(triggered()), this, SLOT(demandeAProposDe()));
    QObject::connect(ui->actionVitesse, SIGNAL(triggered()), this, SLOT(demandeModVitesse()));
    QObject::connect(ui->actionChargerDiapo, SIGNAL(triggered()), this, SLOT(demandeChargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), this, SLOT(demandeEnleverDiapo()));
    QObject::connect(ui->actionFiltre, SIGNAL(triggered()), this, SLOT(demandeFiltre()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(demandeQuitter()));

}

LecteurVue::~LecteurVue()
{
    delete ui;
}

/*A remplir dans les prochaines versions*/
void LecteurVue::majInterface(Modele::UnEtat e)
{
    switch (e) {
    case Modele::vide :

        break;
    case Modele::pret :

        break;
    case Modele::afficheImage :

        break;
    case Modele::arret :

        break;
    default: break;
    }
}

void LecteurVue::setPresentation(Presentation *p)
{
    laPresentation = p;
}

void LecteurVue::demandeDiapoSuiv()
{
    laPresentation->demandeDiapoSuiv();
}
void LecteurVue::demandeDiapoPrec()
{
    laPresentation->demandeDiapoPrec();
}
void LecteurVue::demandeLancerDiapo()
{
    laPresentation->demandeLancerDiapo();
}
void LecteurVue::demandeArreterDiapo()
{
    laPresentation->demandeArreterDiapo();
}
void LecteurVue::demandeModVitesse()
{
    laPresentation->demandeModVitesse();

}
void LecteurVue::demandeChargerDiapo()
{
    laPresentation->demandeChargerDiapo();

}
void LecteurVue::demandeEnleverDiapo()
{
    laPresentation->demandeEnleverDiapo();
}
void LecteurVue::demandeAProposDe()
{
    laPresentation->demandeAProposDe();
}
void LecteurVue::demandeQuitter()
{
    laPresentation->demandeQuitter();
}

void LecteurVue::demandeFiltre()
{
    laPresentation->demandeFiltre();
}
void LecteurVue::demandeAfficher()
{
    laPresentation->demandeAfficher();
}

