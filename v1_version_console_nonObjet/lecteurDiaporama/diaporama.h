#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include "typeDiaporama.h"
#include "image.h"

#include <vector>
#include <iostream>
#include <vector>
using namespace std;

class Diaporama
{
private:
   std::string titre;     // Titre du diaporama
   int vitesseDefilement; // Vitesse de défilement des images du diaporama

public:
   Diaporama(string, int);                  // Constructeur du diaporama
   Diaporama() = default;                   // Constructeur du diaporama par défaut
   ~Diaporama();                            // Destructeur du diaporama
   void modifierTitre(const std::string &); // Modifier le titre du diaporama
   void modifierVitesse(int &);             // Changer la vitesse de défilement du diaporama

   std::string getTitre() const;                            // Renvoie le titre du diaporama
   std::vector<std::string> getImages() const;              // Renvoie tous les titres des images du diaporama
   int getVitesse() const;                                  // Renvoie la vitesse de défilement
   void setImages(const std::vector<ImageDansDiaporama> &); // Définir les images du diaporama

   void charger(std::vector<Diaporama> &); // Chargement du tableau des diaporamas avec des diaporamas préalablement construits 'en dur'
   void creerDiapoDefaut(Diaporama &);     // créer un diaporama par défaut
   void creerDiapoPant(Diaporama &);       // créer un diaporama pour Pantxika
   void creerDiapoThierry(Diaporama &);    // créer un diaporama pour Thierry
   void creerDiapoYann(Diaporama &);       // créer un diaporama pour Yann
   void creerDiapoManu(Diaporama &);       //  créer un diaporama pour Manu

   std::vector<ImageDansDiaporama> localisationImages; // Images du diaporama
};

#endif // DIAPORAMA_H
