#include <vector>
#include <iostream>
using namespace std;

#include "typeDiaporama.h"
#include "image.h"
#include "diaporama.h"

int main() {
    // Chargement des diaporamas et des images dans les diaporamas
    vector<Diaporama> diaporamas;
    Diaporama diapoDefaut;
    diapoDefaut.charger(diaporamas);

    // Création des autres diaporamas
    Diaporama diapoPantxika("Diaporama Pantxika", 1);
    creerDiapoPant(diapoPantxika);
    diaporamas.push_back(diapoPantxika);

    Diaporama diapoThierry("Diaporama Thierry", 1);
    creerDiapoThierry(diapoThierry);
    diaporamas.push_back(diapoThierry);

    Diaporama diapoYann("Diaporama Yann", 1);
    creerDiapoYann(diapoYann);
    diaporamas.push_back(diapoYann);

    Diaporama diapoManu("Diaporama Manu", 1);
    creerDiapoManu(diapoManu);
    diaporamas.push_back(diapoManu);

    // Créer un lecteur avec le diaporama par défaut
    Lecteur lecteur(0, 0, ' '); // Supposons que le diaporama par défaut est le premier dans le vecteur Diaporamas

    // Afficher l'image courante dans le diaporama courant
    lecteur.afficherImageCouranteDansDiapoCourant(diaporamas[lecteur.diaporamaCourant], lecteur.imageCourante, diaporamas[lecteur.diaporamaCourant].localisationImages[lecteur.imageCourante]);

    // Saisie et traitement des actions
    char choixAction;
    do {
        lecteur.saisieVerifImageCourante(choixAction);
        lecteur.declencherAction(choixAction, diaporamas[lecteur.diaporamaCourant], lecteur.diaporamaCourant, lecteur.imageCourante, diaporamas[lecteur.diaporamaCourant].localisationImages[lecteur.imageCourante]);
    } while (choixAction != 'Q'); // Quitter lorsque l'utilisateur appuie sur 'Q'

    return 0;
}

