#include "lecteurvue.h"
#include "ui_lecteurvue.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    QObject::connect(ui->ButtonAvancer,SIGNAL(clicked()),this,SLOT(Avancer()));
    QObject::connect(ui->ButtonReculer,SIGNAL(clicked()),this,SLOT(Reculer()));
    QObject::connect(ui->ButtonChangeD,SIGNAL(clicked()),this,SLOT(changerDiaporama()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}


void LecteurVue::Avancer()
{
    QDebug("L'utilisateur a avancer d'une slide");
}

void LecteurVue::reculer()
{
    QDebug("L'utilisateur a reculer d'une slide");
}

void LecteurVue::changerDiaporama()
{
    QDebug("L'utilisateur a changer de diaporama");

}
