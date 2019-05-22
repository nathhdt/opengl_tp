#include "vue_median.h"
#include <iostream>


using namespace std;

Vue_Median::Vue_Median(Controleur& _controleur)
	: Vue("FILTRE MEDIAN"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Median::notify()
{
	if (appControleur.ecranActuel() == 2)
		display();
}

void Vue_Median::display()
{
	clear();
	Vue::afficher();

	cout << "\tParametres: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}
