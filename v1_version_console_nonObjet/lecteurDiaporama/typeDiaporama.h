#ifndef TYPE_DIAPORAMA_H
#define TYPE_DIAPORAMA_H


#include "image.h"
#include "diaporama.h"
#include <vector>
#include <iostream>
using namespace std;

class ImageDansDiaporama : public Image {
private:
   int pos;        // Rang de l'image dans le tableau d'images (vector<Images>)
   int rang;       // Rang de l'image dans le diaporama


public:

   ImageDansDiaporama(string titre,string cat ,string chemin,int pos,int rang);      // Constructeur de l’image dans le diaporama
   ImageDansDiaporama() = default; // Constructeur de l’image dans le diaporama par defaut
   void ajouter(std::vector<ImageDansDiaporama> &, const string &);             // Ajouter une image dans le diaporama
   void supprimer(std::vector<ImageDansDiaporama> &, const string &);           // Supprimer une image dans un diaporama
   void modifierPos(int);         // Modifier la position de l’image
   void modifierRang(int);        // Modifier le rang de l’image
   int getPos() const;               // Renvoie la position de l’image
   int getRang() const;              // Renvoie le rang de l’image
};

class Lecteur {
private:
   int diaporamaCourant;  // Identifiant du diaporama courant = indice dans le tableau diaporamas
   int imageCourante;     // Identifiant de l’image courante du diaporama courant = indice de l’image dans le tableau diaporamas[diaporamaCourant].images, trié par ordre croissant de rang
   char pChoixAction;     // Saisie du choix d'action de l'utilisateur vis-à-vis de l'image et diaporama courants


public:
   vector<Diaporama> diaporamas; // Diaporamas du lecteur
   Lecteur(int diaporamaCourant, int imageCourante, char pChoixAction);              // Constructeur du lecteur
   ~Lecteur();             // Destructeur du lecteur
   void avancer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante);         // Incrémente pPosImageCourante, modulo nbImages(pDiaporama)
   void reculer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante);         // Décrémente pPosImageCourante, modulo nbImages(pDiaporama)


   int nbImages(const Diaporama& pDiaporama);         // Affiche la taille du diaporama pDiaporama
   void triCroissantRang(Diaporama &pDiaporama);   // Tri du diaporama pDiaporama par ordre croissant de rang des ses images
   void afficherImageCouranteDansDiapoCourant(Diaporama& pDiaporama, unsigned int pImageCourante, const Image& pImage);   // Affichage à l'écran des infos de l'image courante dans son diaporama
   void declencherAction(char pChoixAction,  Diaporama& pDiaporamas, unsigned int& pDiaporamaCourant,
                         unsigned int& pImageCourante, const Image& pImages);    // Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter
   void saisieVerifImageCourante(char& pChoixAction);    // Saisie du choix d'action de l'utilisateur vis-à-vis de l'image et diaporama courants
   int saisieVerifDiapo(const Diaporama& pDiaporamas);         // Retourne un numéro de diaporama choisi par l'utilisateur (dans la liste des diaporamas existants)


};

#endif // TYPE_DIAPORAMA_H

