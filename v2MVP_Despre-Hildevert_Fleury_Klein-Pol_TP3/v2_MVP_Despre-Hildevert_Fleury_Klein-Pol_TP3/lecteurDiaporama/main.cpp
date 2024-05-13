#include <QApplication>
#include <iostream>

#include "lecteur.h"
#include "imageDansDiaporama.h"
#include "diaporama.h"

#include "lecteurvue.h"
#include "modele.h"
#include "presentation.h"

using namespace std;

/* InfosDiaporamas et Diaporamas : Types intermédiaires utiles tant
 * que le diaporama du lecteur n'est pas chargé depuis la Base de Données.
 * A éliminer lorsque le diaporama du lecteur sera chargé à partir de la BD
 * -----------------------------------------------------------------------*/
struct InfosDiaporama {
    unsigned int id;    // identifiant du diaporama dans la BD
    string titre;       // titre du diaporama
    unsigned int vitesseDefilement;
};
typedef vector<InfosDiaporama> Diaporamas;


/* Spécifications des sous-programmes utilisés par le main()
 * ---------------------------------------------------*/
void charger (Diaporamas& pDiaporamas);
/* Chargement du tableau des infos sur diaporamas avec des diaporamas préalablement construits 'en dur'.
   Dans une version ultérieure, le diaporama courant affiché par le Lecteur de diaporamas sera chargé à partir
   d'une base de données.
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* Chargement des diaporamas (sans leurs images)
     * Le choix du diaporama se fera plus tard via le menu Paramètres */
    Diaporamas diaporamas;
    charger(diaporamas);


    // créer le modèle
    Modele *m = new Modele();

    // créer la présentation
    Presentation *p = new Presentation();

    // créer la vue
    LecteurVue w;

    Lecteur monLecteur;     // positionnement par défaut sur diaporama 0 et sur son unique image

    // faire pointer la présentation vers la vue et le modèle
    p->setVue(&w);
    p->setModele(m);

    // faire pointer la vue vers la présentation
    w.setPresentation(p);

    // initialiser la vue en conformité avec l'état initial du modèle
    w.majInterface(m->getEtat()); // ou p->getVue()->majInterface(m->getEtat());

    monLecteur.afficher();

    // afficher la vue et démarrer la boucle d'attente des messages
    w.show();

    return a.exec();
}

/* Corps des sous-programmes utilisés par le main()
 * -------------------------------------------------*/

void charger(Diaporamas& pDiaporamas)
{
    InfosDiaporama infosACharger;
    // Diaporama de Pantxika
    infosACharger.id = 1;
    infosACharger.titre = "Diaporama Pantxika";
    infosACharger.vitesseDefilement = 2;
    pDiaporamas.push_back(infosACharger);

     // Diaporama de Thierry
    infosACharger.id = 2;
    infosACharger.titre = "Diaporama Thierry";
    infosACharger.vitesseDefilement = 4;
    pDiaporamas.push_back(infosACharger);

     // Diaporama de Yann
    infosACharger.id = 3;
    infosACharger.titre = "Diaporama Yann";
    infosACharger.vitesseDefilement = 2;
    pDiaporamas.push_back(infosACharger);

     // Diaporama de Manu
    infosACharger.id = 4;
    infosACharger.titre = "Diaporama Manu";
    infosACharger.vitesseDefilement = 1;
    pDiaporamas.push_back(infosACharger);

}

