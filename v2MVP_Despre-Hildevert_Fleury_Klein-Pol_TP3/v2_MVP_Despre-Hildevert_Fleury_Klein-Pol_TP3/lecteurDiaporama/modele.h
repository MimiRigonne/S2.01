#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include "lecteur.h"

class Modele : public QObject
{
    Q_OBJECT


public:

    enum UnEtat {vide, pret, afficheImage, arret}; // États possibles du lecteur

    void vider(); // Modifie l'état du lecteur
    void preparer(); // Modifie l'état du lecteur
    void afficherImage(); // Modifie l'état du lecteur
    void arreter(); // Modifie l'état du lecteur

    Modele(UnEtat e = vide, QObject *parent = nullptr); // Constructeur avec l'état initial
    UnEtat getEtat(); // Retourne l'état du lecteur

private:
    UnEtat etat; // État actuel du lecteur
};

#endif // MODELE_H

