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

    QObject::connect(ui->actionAProposDe, &QAction::triggered, this, SLOT(demandeAProposDe()));
    QObject::connect(ui->actionVitesse, &QAction::triggered, this, SLOT(demandeModVitesse()));
    QObject::connect(ui->actionChargerDiapo, &QAction::triggered, this, SLOT(demandeChargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, &QAction::triggered, this, SLOT(demandeEnleverDiapo()));
    QObject::connect(ui->actionFiltre, &QAction::triggered, this, SLOT(demandeFiltre()));
    QObject::connect(ui->actionQuitter, &QAction::triggered, this, SLOT(demandeQuitter()));

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
void Presentation::demandeFiltre()
{
    laPresentation->demandeFiltre();
}
void Presentation::demandeAfficher()
{
    laPresentation->demandeAfficher();
}


