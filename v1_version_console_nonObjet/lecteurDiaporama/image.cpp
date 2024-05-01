#include "image.h"

Image::Image(std::string unTitre, std::string uneCategorie, std::string unChemin) :

                                                                                    titre(unTitre),
                                                                                    categorie(uneCategorie),
                                                                                    chemin(unChemin)

{
    // Constructeur de l'image
}

void Image::modifierTitre(std::string newTitre)
{
    // Modifier le titre de l'image
    titre = newTitre;
}

void Image::modifierCat(std::string newCat)
{
    // Modifier la catégorie de l'image
    // Code pour modifier la catégorie

    categorie = newCat;
}

void Image::deplacer(std::string newChemin)
{
    // Modifier le chemin de l'image
    // Code pour déplacer l'image

    chemin = newChemin;
}

const std::string &Image::getCategorie() const
{
    // Renvoie la catégorie de l'image
    return categorie;
}

const std::string &Image::getTitre() const
{
    // Renvoie le titre de l'image
    return titre;
}

const std::string &Image::getChemin() const
{
    // Renvoie le chemin de l'image
    return chemin;
}

void Image::afficher() const
{
    // Afficher le titre, la catégorie et le chemin de l'image
    std::cout << "Titre : " << getTitre() << std::endl;
    std::cout << "Categorie : " << getCategorie() << std::endl;
    std::cout << "Chemin : " << getChemin() << std::endl;
    std::cout << "" << std::endl;
}

void Image::charger(std::vector<Image> &images)
{
    // Chargement du tableau des images avec seules les informations textuelles de quelques images

    Image imageACharger1("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    images.push_back(imageACharger1);

    Image imageACharger2("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    images.push_back(imageACharger2);

    Image imageACharger3("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    images.push_back(imageACharger3);

    Image imageACharger4("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    images.push_back(imageACharger4);

    Image imageACharger5("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    images.push_back(imageACharger5);

    Image imageACharger6("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    images.push_back(imageACharger6);

    Image imageACharger7("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    images.push_back(imageACharger7);

    Image imageACharger8("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    images.push_back(imageACharger8);
}
