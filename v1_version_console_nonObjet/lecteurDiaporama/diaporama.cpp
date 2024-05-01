#include "diaporama.h"

// Constructeur du diaporama
Diaporama::Diaporama(string title, int vit) : titre(title),
                                              vitesseDefilement(vit)
{
}

// Destructeur du diaporama
Diaporama::~Diaporama() {}

// Modifier le titre du diaporama
void Diaporama::modifierTitre(const std::string &nouveauTitre)
{
    titre = nouveauTitre;
}

// Changer la vitesse de défilement du diaporama
void Diaporama::modifierVitesse(int &nouvelleVitesse)
{
    vitesseDefilement = nouvelleVitesse;
}

// Renvoie le titre du diaporama
std::string Diaporama::getTitre() const
{
    return titre;
}

// Renvoie tous les titres des images du diaporama
std::vector<std::string> Diaporama::getImages() const
{
    std::vector<std::string> titres;
    for (const auto &image : localisationImages)
    {
        titres.push_back(image.getTitre());
    }
    return titres;
}

void Diaporama::setImages(const std::vector<ImageDansDiaporama> &images)
{
    localisationImages = images;
}

// Renvoie la vitesse de défilement
int Diaporama::getVitesse() const
{
    return vitesseDefilement;
}

// Jusqu'ici tout marche!

void creerDiapoDefaut(Diaporama &diapoDefaut)
{

    Image imageACharger;

    // Charger les images avec leurs informations textuelles uniquement
    std::vector<Image> images;
    imageACharger.charger(images);

    // L'unique image du diaporama par défaut
    std::vector<ImageDansDiaporama> imagesDiapo =
        {
            ImageDansDiaporama(images[0].getTitre(), images[0].getCategorie(), images[0].getChemin(), 0, 1)};

    diapoDefaut.setImages(imagesDiapo);
}

void creerDiapoPant(Diaporama &diapoPantxika)
{

    Image imageACharger;

    // Charger les images avec leurs informations textuelles uniquement
    std::vector<Image> images;
    imageACharger.charger(images);

    // Les images du diaporama de Pantxika
    std::vector<ImageDansDiaporama> imagesDiapo = {
        ImageDansDiaporama(images[1].getTitre(), images[1].getCategorie(), images[1].getChemin(), 1, 2),
        ImageDansDiaporama(images[2].getTitre(), images[2].getCategorie(), images[2].getChemin(), 2, 4),
        ImageDansDiaporama(images[3].getTitre(), images[3].getCategorie(), images[3].getChemin(), 3, 1),
        ImageDansDiaporama(images[4].getTitre(), images[4].getCategorie(), images[4].getChemin(), 4, 3)};

    diapoPantxika.setImages(imagesDiapo);
}
void creerDiapoThierry(Diaporama &diapoThierry)
{
    Image imageACharger;

    // Charger les images avec leurs informations textuelles uniquement
    std::vector<Image> images;
    imageACharger.charger(images);

    // Les images du diaporama de Thierry
    std::vector<ImageDansDiaporama> imagesDiapo = {
        ImageDansDiaporama(images[1].getTitre(), images[1].getCategorie(), images[1].getChemin(), 1, 2),
        ImageDansDiaporama(images[2].getTitre(), images[2].getCategorie(), images[2].getChemin(), 2, 3),
        ImageDansDiaporama(images[3].getTitre(), images[3].getCategorie(), images[3].getChemin(), 3, 4),
        ImageDansDiaporama(images[4].getTitre(), images[4].getCategorie(), images[4].getChemin(), 4, 1)};

    diapoThierry.setImages(imagesDiapo);
}
void creerDiapoYann(Diaporama &diapoYann)
{
    Image imageACharger;

    // Charger les images avec leurs informations textuelles uniquement
    std::vector<Image> images;
    imageACharger.charger(images);

    // Les images du diaporama de Yann
    std::vector<ImageDansDiaporama> imagesDiapo = {
        ImageDansDiaporama(images[1].getTitre(), images[1].getCategorie(), images[1].getChemin(), 1, 1),
        ImageDansDiaporama(images[2].getTitre(), images[2].getCategorie(), images[2].getChemin(), 2, 4),
        ImageDansDiaporama(images[3].getTitre(), images[3].getCategorie(), images[3].getChemin(), 3, 3),
        ImageDansDiaporama(images[4].getTitre(), images[4].getCategorie(), images[4].getChemin(), 4, 2)};

    diapoYann.setImages(imagesDiapo);
}

void creerDiapoManu(Diaporama &diapoManu)
{

    Image imageACharger;

    // Charger les images avec leurs informations textuelles uniquement
    std::vector<Image> images;
    imageACharger.charger(images);

    // Les images du diaporama de Manu
    std::vector<ImageDansDiaporama> imagesDiapo = {
        ImageDansDiaporama(images[1].getTitre(), images[1].getCategorie(), images[1].getChemin(), 1, 3),
        ImageDansDiaporama(images[2].getTitre(), images[2].getCategorie(), images[2].getChemin(), 2, 2),
        ImageDansDiaporama(images[3].getTitre(), images[3].getCategorie(), images[3].getChemin(), 3, 1),
        ImageDansDiaporama(images[4].getTitre(), images[4].getCategorie(), images[4].getChemin(), 4, 4)};

    diapoManu.setImages(imagesDiapo);
}

// Chargement du tableau des diaporamas avec des diaporamas préalablement construits 'en dur'
void Diaporama::charger(std::vector<Diaporama> &diaporamas)
{

    // Diaporama Defaut
    Diaporama diapoDefaut("Diaporama par defaut", 1);
    // Créer diaporama
    creerDiapoDefaut(diapoDefaut);
    // Mettre le diapo dans la liste des diapos
    diaporamas.push_back(diapoDefaut);
}