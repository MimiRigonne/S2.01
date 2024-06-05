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
    dlg=new AProposDe(this);

    lecteur = new Lecteur();

    timer = new QTimer();

    ui->setupUi(this);

    // Arreter mode auto et suivre les clics des boutons
    QObject::connect(ui->btnSuivant, &QPushButton::clicked, this, &LecteurVue::arreterDiapo);
    QObject::connect(ui->btnPrecedent, &QPushButton::clicked, this, &LecteurVue::arreterDiapo);

    QObject::connect(ui->btnSuivant, &QPushButton::clicked, this, &LecteurVue::btnSuivantClique);

    QObject::connect(ui->btnSuivant, &QPushButton::clicked, this, &LecteurVue::suivant);
    QObject::connect(ui->btnPrecedent, &QPushButton::clicked, this, &LecteurVue::precedent);

    QObject::connect(ui->btnLancerDiapo, &QPushButton::clicked, this, &LecteurVue::lancerDiapo);
    QObject::connect(ui->btnArreterDiapo, &QPushButton::clicked, this, &LecteurVue::arreterDiapo);

    QObject::connect(ui->actionAProposDe, &QAction::triggered, this, &LecteurVue::aProposDe);
    QObject::connect(ui->actionVitesse, &QAction::triggered, this, &LecteurVue::modifierVitesse);
    QObject::connect(ui->actionChargerDiapo, &QAction::triggered, this, &LecteurVue::chargerDiapo);
    QObject::connect(ui->actionEnleverDiapo, &QAction::triggered, this, &LecteurVue::enleverDiapo);
    QObject::connect(ui->actionFiltre, &QAction::triggered, this, &LecteurVue::filtre);

    QObject::connect(ui->actionQuitter, &QAction::triggered, this, &LecteurVue::quitter);

    quitShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q), this);
    QObject::connect(quitShortcut, &QShortcut::activated, this, &LecteurVue::quitter);

    AProposShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_A), this);
    QObject::connect(AProposShortcut, &QShortcut::activated, this, &LecteurVue::aProposDe);
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::btnSuivantClique()
{
    btnSuivClique = true;
}

void LecteurVue::suivant()
{
    if (diapoAutoEnCours && btnSuivClique)
    {
        arreterDiapo();
        btnSuivClique = false; // Réinitialiser l'indicateur du bouton cliqué
        return;
    }
    ui->labelImage->hide();

    lecteur->avancer();

    QString chemin = QString::fromStdString(lecteur->getImageCourante()->getChemin());

    ui->labelImage->setPixmap(QPixmap(chemin));

    ui->labelImage->show();
    qDebug() << "L'utilisateur a avancé d'une diapositive";
}

void LecteurVue::precedent()
{
    if (diapoAutoEnCours)
    {
        arreterDiapo();
        return;
    }

    ui->labelImage->hide();

    lecteur->reculer();

    QString chemin = QString::fromStdString(lecteur->getImageCourante()->getChemin());

    ui->labelImage->setPixmap(QPixmap(chemin));

    ui->labelImage->show();
    qDebug() << "L'utilisateur a reculé d'une diapositive";
}

void LecteurVue::lancerDiapo()
{
    ui->btnArreterDiapo->setEnabled(true);

    ui->labelImage->hide();

    // Commencer à la première image
    unsigned int idDiapo = lecteur->getIdDiaporama();
    lecteur->viderLecteur();
    lecteur->changerDiaporama(idDiapo);

    qDebug() << "L'utilisateur a lancé le diaporama en mode automatique";

    // Connecter le signal timeout() de QTimer à suivant
    connect(timer, &QTimer::timeout, this, &LecteurVue::suivant);

    // Démarrer le timer pour déclencher la fonction suivant() toutes les 2 secondes
    timer->start(2000);

    // Marquer que le diaporama automatique est en cours
    diapoAutoEnCours = true;
}

void LecteurVue::arreterDiapo()
{
    if (diapoAutoEnCours)
    {
        ui->btnArreterDiapo->setEnabled(false);

        qDebug() << "L'utilisateur a arrêté le mode automatique.";

        // Arrêter le timer
        timer->stop();

        diapoAutoEnCours = false;
    }
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
