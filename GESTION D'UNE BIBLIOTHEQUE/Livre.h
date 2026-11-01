#pragma once
#include<iostream>
#include "Date.h"
#include"Livre.h"
using namespace std;
namespace gestionBibliotheque {

	class Livre
	{
	private:
		const int id;
		string titre, auteur;
		Date parution;
		int * notes;
		int nbNotes;
		static int compteurId;
		static int nbInstances;
		
	public:
		Livre(string t, string a, Date d);
		void ajouterNote(int note);
        double calculerMoyenne() const;
		void afficher() const;
		Livre(const Livre&);
		Livre operator=(const Livre&);
		string getTitre()const;
		string getid()const;
		

		~Livre();



	};
}
