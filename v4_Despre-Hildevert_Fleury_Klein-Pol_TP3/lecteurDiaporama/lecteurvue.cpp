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
    //Instances
    dlg=new AProposDe(this);
    lecteur = new Lecteur();
    timer = new QTimer();

    ui->setupUi(this);

    //Mode Manuel
    ui->labelModeLect->setText("Mode Manuel");

    ui->labelImage->setText("Pas de diaporama chargé");

    //Désactiver les labels sauf charger
    ui->actionEnleverDiapo->setDisabled(true);
    ui->actionFiltre->setDisabled(true);
    ui->actionQuitter->setDisabled(true);
    ui->btnPrecedent->setDisabled(true);
    ui->btnSuivant->setDisabled(true);
    ui->btnLancerDiapo->setDisabled(true);
    ui->actionVitesse->setDisabled(true);

    //Cacher les labels
    ui->labelSur->hide();
    ui->labelCat->hide();
    ui->labelCatImg->hide();
    ui->labelImage->hide();
    ui->labelModeLect->hide();
    ui->labelImage->hide();
    ui->labelNbImg->hide();
    ui->labelRangImg->hide();
    ui->labelTitre->hide();
    ui->labelTitreDiapo->hide();
    ui->labelTitreImg->hide();


    // Arreter mode auto
    QObject::connect(ui->btnSuivant, &QPushButton::clicked, this, &LecteurVue::arreterDiapo);
    QObject::connect(ui->btnPrecedent, &QPushButton::clicked, this, &LecteurVue::arreterDiapo);

    // Connecter le signal timeout() de QTimer à suivant
    connect(timer, &QTimer::timeout, this, &LecteurVue::suivantAuto);

    // Autres connexions
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

    //Quitter
    QObject::connect(ui->actionQuitter, &QAction::triggered, this, &LecteurVue::quitter);

    //QObject::connect(m_btnQuitter, SIGNAL(clicked()), QCoreApplication::instance(), SLOT(quit()));
    quitShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q), this);
    QObject::connect(quitShortcut, &QShortcut::activated, this, &LecteurVue::quitter);

    //AProposDe
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
    if (diapoAutoEnCours)
    {
        arreterDiapo();
        return;
    }

    lecteur->avancer();
    changerLabelsImg();
}

void LecteurVue::suivantAuto()
{
    lecteur->avancer();
    changerLabelsImg();

}

void LecteurVue::changerLabelsImg()
//Changer les labels sur l'image
{
    QString chemin = QString::fromStdString(lecteur->getImageCourante()->getChemin());
    ui->labelImage->setPixmap(QPixmap(chemin));


    ui->labelTitreImg->setText(QString::fromStdString(lecteur->getImageCourante()->getTitre()));

    int rang = lecteur->getImageCourante()->getRangDansDiaporama();
    ui->labelRangImg->setText(QString::number(rang));

    ui->labelCatImg->setText(QString::fromStdString(lecteur->getImageCourante()->getCategorie()));
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

}

void LecteurVue::lancerDiapo()
{
    ui->btnArreterDiapo->setEnabled(true);

    ui->labelModeLect->hide();
    ui->labelModeLect->setText("Mode Automatique");
    ui->labelModeLect->show();

    // Afficher la première image
    Diaporama* diapoCourant = lecteur->getDiaporama();
    lecteur->setPosImageCourante(diapoCourant->nbImages()-1); //dernière image
    lecteur->avancer();
    changerLabelsImg();

    // Démarrer le timer pour déclencher la fonction suivant() toutes les 2 secondes
    timer->start(2000);

    // Marquer que le diaporama automatique est en cours
    diapoAutoEnCours = true;

}

void LecteurVue::arreterDiapo()
{
    if (diapoAutoEnCours)
    {
        // Arrêter le timer
        timer->stop();

        ui->labelModeLect->setText("Mode Manuel");

        ui->btnArreterDiapo->setEnabled(false);

        diapoAutoEnCours = false;
    }
}

void LecteurVue::chargerDiapo()
{

    lecteur->changerDiaporama(1, "test");

    Diaporama* diapoCourant = lecteur->getDiaporama();

    QString titre = QString::fromStdString(diapoCourant->getTitre());

    ui->labelTitreDiapo->setText(titre); //Titre diapo

    ui->labelNbImg->setText(QString::number(diapoCourant->nbImages())); //nb images du diapo

    //Montrer les labels
    ui->labelSur->show();
    ui->labelCat->show();
    ui->labelCatImg->show();
    ui->labelImage->show();
    ui->labelModeLect->show();
    ui->labelImage->show();
    ui->labelNbImg->show();
    ui->labelRangImg->show();
    ui->labelTitre->show();
    ui->labelTitreDiapo->show();
    ui->labelTitreImg->show();


    // Commencer à la première image
    lecteur->setPosImageCourante(0);
    changerLabelsImg();

    //activer boutons et labels
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
    //vider le lecteur s'il ne l'est pas déjà
    if(!lecteur->lecteurVide())
    {
        enleverDiapo();
    }

    QCoreApplication::instance()->quit();

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
    ui->labelImage->setText("Pas de diaporama chargé");

    //Cacher les labels
    ui->labelSur->hide();
    ui->labelCat->hide();
    ui->labelCatImg->hide();
    ui->labelImage->hide();
    ui->labelModeLect->hide();
    ui->labelImage->hide();
    ui->labelNbImg->hide();
    ui->labelRangImg->hide();
    ui->labelTitre->hide();
    ui->labelTitreDiapo->hide();
    ui->labelTitreImg->hide();

}
