#pragma once
#include "Date.h"
using namespace std;
namespace gestionBibliotheque {

	class Date
	{
	private:
		int jour, mois, annee;
	public:
		Date(int j, int m, int a );
		bool estValide(int j, int m, int a);
		bool estBissextile(int a);
		bool operator==(const Date d)const;
		bool operator<(const Date d)const;
		void afficher();
	};
}

