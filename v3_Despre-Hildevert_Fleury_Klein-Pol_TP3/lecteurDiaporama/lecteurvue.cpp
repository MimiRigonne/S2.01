#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <QAction>
#include <QCoreApplication>
#include "aproposde.h"

#include "lecteur.h"
#include "imagedansdiaporama.h"
#include "diaporama.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    QObject::connect(ui->btnSuivant,SIGNAL(clicked()),this,SLOT(suivant()));
    QObject::connect(ui->btnPrecedent,SIGNAL(clicked()),this,SLOT(precedent()));
    QObject::connect(ui->btnLancerDiapo,SIGNAL(clicked()),this,SLOT(lancerDiapo()));
    QObject::connect(ui->btnArreterDiapo,SIGNAL(clicked()),this,SLOT(arreterDiapo()));

    QObject::connect(ui->actionAProposDe, &QAction::triggered, this, &LecteurVue::aProposDe);
    QObject::connect(ui->actionVitesse, &QAction::triggered, this, &LecteurVue::modifierVitesse);
    QObject::connect(ui->actionChargerDiapo, &QAction::triggered, this, &LecteurVue::chargerDiapo);
    QObject::connect(ui->actionEnleverDiapo, &QAction::triggered, this, &LecteurVue::enleverDiapo);
    QObject::connect(ui->actionFiltre, &QAction::triggered, this, &LecteurVue::filtre);

    QObject::connect(ui->actionQuitter, &QAction::triggered, this, &LecteurVue::quitter);

    quitShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q), this);
    QObject::connect(quitShortcut, &QShortcut::activated,this, &LecteurVue::quitter);

    AProposShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_A), this);
    connect(AProposShortcut, &QShortcut::activated, this, &LecteurVue::aProposDe);

    dlg=new AProposDe(this);

    lecteur = new Lecteur();
}

LecteurVue::~LecteurVue()
{
    delete ui;
}


void LecteurVue::suivant() {

    ui->labelImage->hide();

    lecteur->avancer();

    QString chemin = QString::fromStdString(lecteur->getImageCourante()->getChemin());

    ui->labelImage->setPixmap(QPixmap(chemin));

    ui->labelImage->show();
    qDebug() << "L'utilisateur a avancé d'une diapositive";
}

void LecteurVue::precedent() {

    ui->labelImage->hide();

    lecteur->reculer();

    QString chemin = QString::fromStdString(lecteur->getImageCourante()->getChemin());

    ui->labelImage->setPixmap(QPixmap(chemin));

    ui->labelImage->show();
    qDebug() << "L'utilisateur a reculé d'une diapositive";
}


void LecteurVue::lancerDiapo()
{
    qDebug() << "L'utilisateur a lancé le diaporama en mode automatique";

}

void LecteurVue::arreterDiapo()
{
    qDebug() << "L'utilisateur a arrêté le mode automatique.";

}

void LecteurVue::chargerDiapo()
{
    lecteur->changerDiaporama(1, "test");
    qDebug() << "L'utilisateur a chargé un diaporama";

}

void LecteurVue::quitter()
{
    qDebug() << "L'utilisateur a quitté le lecteur";

    if (lecteur->lecteurVide()) {
        QCoreApplication::instance()->quit();
    } else {
        qDebug() << "Erreur: Impossible de quitter car le lecteur n'est pas vide.";
    }
}

void LecteurVue::modifierVitesse()
{
    qDebug() << "L'utilisateur a modifié la vitesse";

}


void LecteurVue::filtre()
{
    qDebug() << "L'utilisateur a filtré les images par catégorie";

}

void LecteurVue::aProposDe()
{

    dlg->show();
}


void LecteurVue::enleverDiapo()
{
    lecteur->viderLecteur();
    ui->labelImage->hide();
    ui->labelImage->setText("");
    qDebug() << "L'utilisateur a enlevé le diaporama";

}





