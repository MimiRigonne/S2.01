#include "modele.h"

Modele::Modele(UnEtat e, QObject *parent)
: QObject{parent}, etat(e)
{
}

void Modele::vider()
{
    etat = UnEtat::vide;
}
void Modele::preparer()
{
    etat = UnEtat::pret;
}
void Modele::afficherImage()
{
    etat = UnEtat::afficheImage;
}
void Modele::arreter()
{
    etat = UnEtat::arret;
}
Modele::UnEtat Modele::getEtat()
{
    return etat;
}
