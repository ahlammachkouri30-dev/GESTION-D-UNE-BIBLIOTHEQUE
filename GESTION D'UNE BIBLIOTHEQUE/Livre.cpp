#include "Livre.h"
#include<iostream>
#include "Date.h"
using namespace std;
namespace gestionBibliotheque {

	int Livre::compteurId = 0;
	int Livre::nbInstances = 0;

    Livre::Livre(string t, string a, Date d)

        : id(compteurId++), titre(t), auteur(a),

        parution(d), notes(nullptr), nbNotes(0) {

        nbInstances++;

        cout << "Construction du livre : " << titre << endl;

    }

    

    void Livre::ajouterNote(int note) {

        if (note < 0 || note > 20) {

            cout << "note invalide !" << endl;

            return;

        }

        int* nouveau = new int[nbNotes + 1];

        for (int i = 0; i < nbNotes; i++) {

            nouveau[i] = notes[i];

        }

        nouveau[nbNotes] = note;

        delete[] notes;

        notes = nouveau;

        nbNotes++;

    }

    

    double Livre::calculerMoyenne() const {

        if (nbNotes == 0)

            return 0;

        double somme = 0;

        for (int i = 0; i < nbNotes; i++) {

            somme += notes[i];

        }

        return somme / nbNotes;

    }

   

    void Livre::afficher() const {

        cout << "\n ID : " << id << endl;

        cout << "Titre : " << titre << endl;

        cout << "Auteur : " << auteur << endl;

        cout << "Date de parution : ";

        parution.afficher();

        cout << "\nNombre de notes : " << nbNotes << endl;

        cout << "Notes : ";

        for (int i = 0; i < nbNotes; i++) {

            cout << notes[i] << " ";

        }

        cout << "\nMoyenne : " << calculerMoyenne() << endl;

    }

	gestionBibliotheque::Livre::Livre(const Livre &l) :id(++compteurId), titre(l.titre), auteur(l.auteur), parution(l.parution), notes(nullptr), nbNotes(l.nbNotes) {

		if (nbNotes > 0)
		{
			notes = new int[nbNotes];

			for (int i = 0; i < nbNotes; i++)
				notes[i] = l.notes[i];
		}

		nbInstances++;
	}


    Livre Livre::operator=(const Livre& l)
    {
        if (this != &l)
        {
            this->titre = l.titre;
            this-> auteur = l.auteur;
            this->parution = l.parution;

            int* notes = nullptr;

            if (l.nbNotes > 0)
            {
                notes = new int[l.nbNotes];

                for (int i = 0; i < l.nbNotes; i++)
                    notes[i] = l.notes[i];
            }}

        return *this;
    }

    string Livre::getTitre()const
    {
        return titre;
    }

    string Livre::getid() const
    {
        return string();
    }



    Livre::~Livre()
    {
        delete[] notes;
        notes = nullptr;
        nbInstances--;
    }

	}

