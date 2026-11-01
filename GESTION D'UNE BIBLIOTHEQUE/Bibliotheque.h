#pragma once
#include<iostream>
#include "Date.h"
#include "Livre.h"
using namespace std;
namespace gestionBibliotheque {

	class Bibliotheque
	{
	private:
		string nom;
		Livre** Livres;
		int capacite;
		int nbLivres;
		int nbBibliotheque;
	public:
		Bibliotheque(string n, int c);
		void ajouterLivre(Livre* l);
		Livre* rechercherParTitre(string t) const;
		Livre* rechercherParId(int id) const;
		void afficherCatalogue() const;
		Bibliotheque(const Bibliotheque& B);
		Bibliotheque operator=(const Bibliotheque& B);
		~Bibliotheque();



	};

}