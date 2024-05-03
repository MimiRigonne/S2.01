#include "lecteurvue.h"
#include "ui_lecteurvue.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    QObject::connect(ui->btnSuivant,SIGNAL(clicked()),this,SLOT(suivant()));
    QObject::connect(ui->btnPrecedent,SIGNAL(clicked()),this,SLOT(precedent()));
    QObject::connect(ui->btnLancerDiapo,SIGNAL(clicked()),this,SLOT(lancerDiapo()));
    QObject::connect(ui->btnArreterDiapo,SIGNAL(clicked()),this,SLOT(arreterDiapo()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}


void LecteurVue::suivant() {
    qDebug() << "L'utilisateur a avancé d'une diapositive";
}

void LecteurVue::precedent() {
    qDebug() << "L'utilisateur a reculé d'une diapositive";
}


void LecteurVue::lancerDiapo()
{
    qDebug() << "L'utilisateur a lancé le diaporama";

}

void LecteurVue::arreterDiapo()
{
    qDebug() << "L'utilisateur a arrêté le diaporama";

}
