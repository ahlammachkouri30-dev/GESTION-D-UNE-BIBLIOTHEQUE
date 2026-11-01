#include "Bibliotheque.h"
#include "Livre.h"
namespace gestionBibliotheque {

gestionBibliotheque::Bibliotheque::Bibliotheque(const Bibliotheque& B)
{
	this->nom = B.nom;
	this->capacite = B.capacite;
	this->nbLivres = B.nbLivres;
	this->nbBibliotheque = B.nbBibliotheque;

	this-> Livres = new Livre * [capacite];
	for (int i = 0;i < B.nbLivres;i++) {
        this->Livres[i] = new Livre(*B.Livres[i]);;

	}
}

void Bibliotheque::ajouterLivre(Livre* l) {

    if (nbLivres >= capacite) {

        cout << "Capacite maximale atteinte !" << endl;

        return;

    }

    Livres[nbLivres] = l;

    nbLivres++;

    cout << "Livre ajoute avec succes !" << endl;

}

Livre* Bibliotheque::rechercherParTitre(string t) const {

    for (int i = 0; i < nbLivres; i++) {

        if (Livres[i]->getTitre() == t) {

            return Livres[i];

        }

    }

    return nullptr;

}

Livre* Bibliotheque::rechercherParId(int id) const {

    for (int i = 0; i < nbLivres; i++) {

        if (Livres[i]->getid() == id) {

            return Livres[i];

        }

    }

    return nullptr;

}

void Bibliotheque::afficherCatalogue() const {

    cout << "\n===== CATALOGUE DE " << nom << " =====" << endl;

    for (int i = 0; i < nbLivres; i++) {

        Livres[i]->afficher();

    }

}
gestionBibliotheque::Bibliotheque::operator=(const Bibliotheque& B)
{
    if (this != &B)
    {
        for (int i = 0; i < nbLivres; i++)
        {
            delete Livres[i];
        }

        delete[] Livres;

        this->Livres = new Livre * [capacite];
        for (int i = 0;i < B.nbLivres;i++) {
            this->Livres[i] = new Livre(*B.Livres[i]);;
       
        }
    }
}

Bibliotheque::~Bibliotheque()
{
    
        for (int i = 0; i < nbLivres; i++)
        {
            delete Livres[i];
        }

        delete[] Livres;
    
}

}