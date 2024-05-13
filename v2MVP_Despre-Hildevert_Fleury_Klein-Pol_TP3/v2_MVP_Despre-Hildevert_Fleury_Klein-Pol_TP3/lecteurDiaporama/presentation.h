#include <QObject>
#include <QDebug>

#include "modele.h"
#include "lecteurvue.h"

class LecteurVue; // déclaration du mot-clé LecteurVue

class Presentation : public QObject
{
    Q_OBJECT

private:

    Modele *_leModele; // Pointeur sur le modèle
    LecteurVue *_laVue; // Pointeur sur la vue

public:
    Presentation(QObject *parent = nullptr); // Constructeur de la classe Presentation
    Modele* getModele(); // Renvoie le modèle
    LecteurVue* getVue(); // Renvoie la vue
    void setModele(Modele *m); // Définit le modèle
    void setVue(LecteurVue *v); // Définit la vue

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
