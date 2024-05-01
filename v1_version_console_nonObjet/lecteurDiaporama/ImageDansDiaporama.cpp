#include "typeDiaporama.h"

// Constructeur de l’image dans le diaporama
ImageDansDiaporama::ImageDansDiaporama(string titre, string cat, string chemin, int pos, int rang) : Image(titre, cat, chemin),
                                                                                                     pos(pos),
                                                                                                     rang(rang)
{
}

// Modifier la position de l’image
void ImageDansDiaporama::modifierPos(int newPos)
{
    pos = newPos;
}

// Modifier le rang de l’image
void ImageDansDiaporama::modifierRang(int newRang)
{
    rang = newRang;
}

// Renvoie la position de l’image
int ImageDansDiaporama::getPos() const
{
    return pos;
}

// Renvoie le rang de l’image
int ImageDansDiaporama::getRang() const
{
    return rang;
}
