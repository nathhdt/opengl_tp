#include "vue_charger.h"
#include <iostream>


using namespace std;

Vue_Charger::Vue_Charger(Controleur& _controleur)
	: Vue("CHARGER UNE IMAGE"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Charger::notify()
{
	if (appControleur.ecranActuel() == 1)
		display();
}

void Vue_Charger::display()
{
	clear();
	Vue::afficher();

	cout << "\tChemin vers l'image: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}
