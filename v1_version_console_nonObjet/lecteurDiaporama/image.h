#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <iostream>
using namespace std;

class Image
{
private:
    std::string titre;     // Intitulé de l'image
    std::string categorie; // Catégorie de l'image (personne, animal, objet)
    std::string chemin;    // Chemin de l'image sur le système de fichiers

public:
    Image() = default;                            // Constructeur de l'image par defaut
    Image(std::string, std::string, std::string); // Constructeur de l'image
    void afficher() const;                        // Afficher le titre, la catégorie et le chemin de l'image
    void modifierTitre(std::string);              // Modifier le titre de l'image
    void modifierCat(std::string);                // Modifier la catégorie de l'image
    void deplacer(std::string);                   // Modifier le chemin de l'image
    const std::string &getCategorie() const;      // Renvoie la catégorie de l'image
    const std::string &getTitre() const;          // Renvoie le titre de l'image
    const std::string &getChemin() const;         // Renvoie le chemin de l'image
    void charger(std::vector<Image> &);           // Chargement du tableau des images avec seules les informations textuelles de quelques images
};

#endif