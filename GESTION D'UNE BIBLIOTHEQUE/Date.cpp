#include "Date.h"
#include<iostream>
using namespace std;
namespace gestionBibliotheque {


	Date::Date(int j, int m, int a)
	{
		if (estValide(j, m, a)) {
			this->jour = j;
			this->mois = m;
			this->annee = a;
		}
		else {
			this->jour = 1;
			this->mois = 1;
			this->annee = 2000;
		}

	}



	bool Date::estValide(int j, int m, int a)
	{
		if (j < 1 || j>31 || a < 2000 || m < 1 || m>12) {

			cout << "erreur" << endl;
			return false;

			int joursMois[] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };

			if (estBissextile(a))

				joursMois[1] = 29;

			return j <= joursMois[m - 1];

		}
	}



			bool Date::estBissextile(int a)
			{
				if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
					cout << "annee Bissextile" << endl;
				return true;

				cout << "annee non Bissextile" << endl;
				return false;
			}
		



		bool Date::operator==(const Date d) const
		{
			return (this->jour == d.jour) && (this->mois == d.mois) && (this->annee == d.annee);

		}



		bool Date::operator<(const Date d) const
		{
			return (this->jour < d.jour) && (this->mois < d.mois) && (this->annee < d.annee);

		}

		void Date::afficher()
		{
			cout << jour << "/" << mois << "/" << annee;

		}



	}






	






