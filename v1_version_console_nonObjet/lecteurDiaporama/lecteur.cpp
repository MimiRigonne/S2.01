#include "typeDiaporama.h"

// Déclaration et initialisation du vecteur de Diaporamas
vector<Diaporama> Diaporamas;

// Implémentation des méthodes de la classe Lecteur

Lecteur::Lecteur(int diapoCourant, int imgCourante, char choixAction) : diaporamaCourant(diapoCourant),
                                                                        imageCourante(imgCourante),
                                                                        pChoixAction(choixAction)
{
}

Lecteur::~Lecteur() {}

void Lecteur::avancer(const Diaporama &pDiaporama, unsigned int &pPosImageCourante)
{
    if (pPosImageCourante == pDiaporama.localisationImages.size() - 1)
    {
        pPosImageCourante = 0;
    }
    else
    {
        pPosImageCourante++;
    }
}

void Lecteur::reculer(const Diaporama &pDiaporama, unsigned int &pPosImageCourante)
{
    if (pPosImageCourante == 0)
    {
        pPosImageCourante = pDiaporama.localisationImages.size() - 1;
    }
    else
    {
        pPosImageCourante--;
    }
}

int Lecteur::nbImages(const Diaporama &pDiaporama)
{
    return pDiaporama.localisationImages.size();
}

void Lecteur ::triCroissantRang(Diaporama &pDiaporama)
{
    // par la méthode du triBulle
    unsigned int taille = pDiaporama.getImages().size();
    ImageDansDiaporama imageDansDiapo;
    for (unsigned int ici = taille - 1; ici >= 1; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (pDiaporama.localisationImages[i].getRang() > pDiaporama.localisationImages[i + 1].getRang())
            {
                // echanger les 2 éléments
                imageDansDiapo = pDiaporama.localisationImages[i];
                pDiaporama.localisationImages[i] = pDiaporama.localisationImages[i + 1];
                pDiaporama.localisationImages[i + 1] = imageDansDiapo;
            }
        }
    }
}

void Lecteur ::afficherImageCouranteDansDiapoCourant(Diaporama &pDiaporama, unsigned int pImageCourante, const Image &pImage)
{
    cout << endl
         << endl;
    cout << "DIAPORAMA : " << pDiaporama.getTitre() << endl
         << endl;
    cout << pDiaporama.localisationImages[pImageCourante].getRang() << " sur " << nbImages(pDiaporama) << " / ";
    afficher(pImage);
}

void Lecteur ::declencherAction(char pChoixAction, Diaporama &pDiaporamas, unsigned int &pDiaporamaCourant,
                                unsigned int &pImageCourante, const Image &pImages)
{
    unsigned int position;
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
    case 'A':
        avancer(pDiaporamas[pDiaporamaCourant], pImageCourante);
        position = pDiaporamas[pDiaporamaCourant].localisationImages[pImageCourante].pos;
        afficherImageCouranteDansDiapoCourant(pDiaporamas[pDiaporamaCourant], pImageCourante, pImages[position]);
        break;
    case 'R':
        reculer(pDiaporamas[pDiaporamaCourant], pImageCourante);
        position = pDiaporamas[pDiaporamaCourant].localisationImages[pImageCourante].pos;
        afficherImageCouranteDansDiapoCourant(pDiaporamas[pDiaporamaCourant], pImageCourante, pImages[position]);
        break;
    case 'C':
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = saisieVerifDiapo(pDiaporamas);
        // Changer de diaporama
        pDiaporamaCourant = choixDiaporama;
        pImageCourante = 0;
        break;

    default:
        break;
    }
}

void Lecteur ::saisieVerifImageCourante(char &pChoixAction)
{
    cout << endl
         << endl;
    while (true)
    {
        cout << endl;
        cout << "ACTIONS :"
             << "  A-vancer"
             << "  R-eculer"
             << "  C-hanger de diaporama "
             << "  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'Q'))
        {
            break;
        }
    }
}

int Lecteur ::saisieVerifDiapo(const Diaporama &pDiaporamas)
{
    unsigned int choixSaisi;
    int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls"); // effacer l'écran
        cout << endl
             << endl
             << "CHANGEMENT DIAPORAMA : " << endl
             << endl;
        for (unsigned int num = 1; num < pDiaporamas.getImages().size(); num++)
        {
            cout << num << ": " << pDiaporamas[num].titre;
            if (num != pDiaporamas.size() - 1)
            {
                cout << endl;
            }
        }
        cout << ".......  votre choix ? ";
        cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1) && (choixDiaporama < static_cast<unsigned int>(pDiaporamas.size())))
        {
            break;
        }
    }
    return choixDiaporama;
}
