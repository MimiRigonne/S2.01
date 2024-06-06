#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <QAction>
#include <QCoreApplication>
#include "aproposde.h"

#include <QString>

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

    ui->labelModeLect->setText("Mode Manuel");

    ui->actionEnleverDiapo->setDisabled(true);
    ui->actionFiltre->setDisabled(true);
    ui->actionQuitter->setDisabled(true);
    ui->btnPrecedent->setDisabled(true);
    ui->btnSuivant->setDisabled(true);
    ui->btnLancerDiapo->setDisabled(true);
    ui->actionVitesse->setDisabled(true);

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
        btnSuivClique = false; // Réinitialiser l'indicateur du bouton cliqué
        arreterDiapo();
        return;
    }

    lecteur->avancer();
    changerLabelsImg();


    qDebug() << "L'utilisateur a avancé d'une diapositive";
}

void LecteurVue::changerLabelsImg()
//Changer les labels sur l'image
{
    //Cacher
    ui->labelImage->hide();
    ui->labelTitreImg->hide();
    ui->labelRangImg->hide();
    ui->labelCatImg->hide();

    //Changer
    QString chemin = QString::fromStdString(lecteur->getImageCourante()->getChemin());
    ui->labelImage->setPixmap(QPixmap(chemin));


    ui->labelTitreImg->setText(QString::fromStdString(lecteur->getImageCourante()->getTitre()));

    int rang = lecteur->getImageCourante()->getRangDansDiaporama();
    ui->labelRangImg->setText(QString::number(rang));

    ui->labelCatImg->setText(QString::fromStdString(lecteur->getImageCourante()->getCategorie()));

    //Afficher
    ui->labelImage->show();
    ui->labelTitreImg->show();
    ui->labelRangImg->show();
    ui->labelCatImg->show();
}

void LecteurVue::precedent()
{
    if (diapoAutoEnCours)
    {
        arreterDiapo();
        return;
    }

    lecteur->reculer();

    changerLabelsImg();

    qDebug() << "L'utilisateur a reculé d'une diapositive";
}

void LecteurVue::lancerDiapo()
{
    ui->btnArreterDiapo->setEnabled(true);

    ui->labelModeLect->hide();
    ui->labelModeLect->setText("Mode Automatique");
    ui->labelModeLect->show();

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
        ui->labelModeLect->hide();
        ui->labelModeLect->setText("Mode Manuel");
        ui->labelModeLect->show();

        ui->btnArreterDiapo->setEnabled(false);

        qDebug() << "L'utilisateur a arrêté le mode automatique.";

        // Arrêter le timer
        timer->stop();

        diapoAutoEnCours = false;
    }
}

void LecteurVue::chargerDiapo()
{
    ui->labelTitreDiapo->hide();

    lecteur->changerDiaporama(1, "test");

    Diaporama* diapoCourant = lecteur->getDiaporama();

    qDebug() << "L'utilisateur a chargé un diaporama";

    QString titre = QString::fromStdString(diapoCourant->getTitre());

    ui->labelTitreDiapo->setText(titre);

    ui->actionEnleverDiapo->setEnabled(true);
    ui->actionFiltre->setEnabled(true);
    ui->actionQuitter->setEnabled(true);
    ui->btnPrecedent->setEnabled(true);
    ui->btnSuivant->setEnabled(true);
    ui->btnLancerDiapo->setEnabled(true);
    ui->actionVitesse->setEnabled(true);
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
