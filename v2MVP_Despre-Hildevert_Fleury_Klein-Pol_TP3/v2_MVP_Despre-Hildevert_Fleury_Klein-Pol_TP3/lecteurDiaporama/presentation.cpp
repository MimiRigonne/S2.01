#include "presentation.h"
#include "lecteurvue.h"

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{
    _leModele->vider();
}
Modele *Presentation::getModele()
{
    return _leModele;
}
LecteurVue *Presentation::getVue()
{
    return _laVue;
}
void Presentation::setModele(Modele *m)
{
    _leModele = m;
}
void Presentation::setVue(LecteurVue *v)
{
    _laVue = v;
}

/*A modifier dans les prochaines versions*/
void Presentation::demandeDiapoSuiv()
{
    qDebug() << "L'utilisateur a avancé d'une diapositive";
    _leModele->afficherImage();
    _laVue->majInterface(_leModele->getEtat());

}
void Presentation::demandeDiapoPrec()
{
    qDebug() << "L'utilisateur a reculé d'une diapositive";
    _leModele->afficherImage();
    _laVue->majInterface(_leModele->getEtat());

}
void Presentation::demandeLancerDiapo()
{
    qDebug() << "L'utilisateur a lancé le diaporama";
    _leModele->preparer();
    _laVue->majInterface(_leModele->getEtat());

}
void Presentation::demandeArreterDiapo()
{
    qDebug() << "L'utilisateur a arrêté le diaporama";
    _leModele->arreter();
    _laVue->majInterface(_leModele->getEtat());
}
void Presentation::demandeModVitesse()
{
    qDebug() << "L'utilisateur a modifié la vitesse";
    _leModele->preparer();
    _laVue->majInterface(_leModele->getEtat());

}
void Presentation::demandeChargerDiapo()
{
    qDebug() << "L'utilisateur a chargé un diaporama";
    _leModele->preparer();
    _laVue->majInterface(_leModele->getEtat());

}
void Presentation::demandeEnleverDiapo()
{
    qDebug() << "L'utilisateur a enlevé le diaporama";
    _leModele->vider();
    _laVue->majInterface(_leModele->getEtat());
}
void Presentation::demandeAProposDe()
{
    qDebug() << "Les informations du à propos de sont affichées";
    _leModele->afficherImage();
    _laVue->majInterface(_leModele->getEtat());

}
void Presentation::demandeQuitter()
{
    qDebug() << "L'utilisateur a quitté le lecteur";
    _leModele->arreter();
    _laVue->majInterface(_leModele->getEtat());

}
void Presentation::demandeFiltre()
{
    qDebug() << "L'utilisateur a filtré les images par catégorie";
    _leModele->afficherImage();
    _laVue->majInterface(_leModele->getEtat());
}
void Presentation::demandeAfficher()
{
    qDebug() << "Le lecteur affiche une image.";
    _leModele->afficherImage();
    _laVue->majInterface(_leModele->getEtat());
}
