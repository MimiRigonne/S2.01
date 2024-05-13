#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QWidget>
#include <QObject>

#include "modele.h"
#include "ui_lecteurvue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class Presentation ; // déclaration du mot-clé Presentation

class LecteurVue : public QMainWindow
{
    Q_OBJECT

private:
    Ui::LecteurVue *ui;
    Presentation* laPresentation; // pointeur sur la Présentation

public:
    LecteurVue(QWidget *parent = nullptr); // Constructeur de la classe LecteurVue
    ~LecteurVue(); // Destructeur
    void nvlleConnexion(QObject *c); // Pour créer une connexion avec la présentation
    void supprConnexion(QObject *c); // Pour supprimer une connexion avec la présentation
    void majInterface(Modele::UnEtat e); // Ordonne la Présentation de MAJ de l’interface en fonction de l’état du modèle
    Presentation* getPresentation(); // Retourne la Présentation
    void setPresentation (Presentation * p); // Définit la Présentation

public slots:

    void demandeDiapoSuiv(); // Demande de diapo suivante
    void demandeDiapoPrec(); // Demande de diapo précédente
    void demandeLancerDiapo(); // Demande de lancement de diaporama
    void demandeArreterDiapo(); // Demande d'arrêt de diaporama
    void demandeModVitesse(); // Demande de modification de vitesse
    void demandeChargerDiapo(); // Demande de chargement de diaporama
    void demandeEnleverDiapo(); // Demande d'enlèvement de diaporama
    void demandeAProposDe(); // Demande d'affichage de la boîte à propos de
    void demandeQuitter(); // Demande de fermeture de l'application
    void demandeFiltre(); // Demande d'application de filtre sur les images
    void demandeAfficher(); // Affiche les informations sur le lecteur, le diaporama et l'image courante (modifier l'ui)


};
#endif // LECTEURVUE_H
