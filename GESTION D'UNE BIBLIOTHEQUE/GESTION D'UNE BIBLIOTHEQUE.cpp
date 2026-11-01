// GESTION D'UNE BIBLIOTHEQUE.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Bibliotheque.h"

using namespace std;
using namespace gestionBibliotheque ;

int main() {

   
    Bibliotheque b("Bibliotheque universitaire", 3);

    
    Date d1(10, 5, 2020);
    Date d2(15, 8, 2021);
    Date d3(20, 3, 2022);

    
    Livre* L1 = new Livre("Programmation C++", "Ahmed", d1);
    Livre* L2 = new Livre("Algorithmique", "Sara", d2);
    Livre* L3 = new Livre("Base de donnees", "Ali", d3);

    
    b.ajouterLivre(L1);
    b.ajouterLivre(L2);
    b.ajouterLivre(L3);

    
    L1->ajouterNote(15);
    L1->ajouterNote(18);
    L1->ajouterNote(16);

    L2->ajouterNote(12);
    L2->ajouterNote(14);
    L2->ajouterNote(17);

    L3->ajouterNote(19);
    L3->ajouterNote(16);
    L3->ajouterNote(18);

    cout << "\n===== RECHERCHE REUSSIE =====" << endl;

    Livre* resultat = b.rechercherParTitre("Algorithmique");

    if (resultat != nullptr) {
        resultat->afficher();
    }
    else {
        cout << "Livre introuvable !" << endl;
    }

    

    cout << " RECHERCHE INFRUCTUEUSE " << endl;

    resultat = b.rechercherParTitre("Mathematiques");

    if (resultat != nullptr) {
        resultat->afficher();
    }
    else {
        cout << "Livre introuvable !" << endl;
    }

    
    cout << "RECHERCHE PAR ID " << endl;

    resultat = b.rechercherParId(1);

    if (resultat != nullptr) {
        resultat->afficher();
    }
    else {
        cout << "Livre introuvable !" << endl;
    }

    
    b.afficherCatalogue();

      

    cout << "\n===== FIN DU PROGRAMME =====" << endl;

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
