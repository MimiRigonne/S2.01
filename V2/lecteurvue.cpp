#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include "QDebug"
LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    QObject::connect(ui->ButtonAvancer,SIGNAL(clicked()),this,SLOT(Avancer()));
    QObject::connect(ui->ButtonReculer,SIGNAL(clicked()),this,SLOT(reculer()));
    QObject::connect(ui->ButtonChangeD,SIGNAL(clicked()),this,SLOT(changerDiaporama()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}


void LecteurVue::Avancer() {
    qDebug() << "L'utilisateur a avancé d'une diapositive";
}

void LecteurVue::reculer() {
    qDebug() << "L'utilisateur a reculé d'une diapositive";
}

void LecteurVue::changerDiaporama() {
    qDebug() << "L'utilisateur a changé de diaporama";
}
