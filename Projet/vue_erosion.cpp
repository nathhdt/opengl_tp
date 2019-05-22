#include "vue_erosion.h"
#include <iostream>


using namespace std;

Vue_Erosion::Vue_Erosion(Controleur& _controleur)
	: Vue("EROSION"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Erosion::notify()
{
	if (appControleur.ecranActuel() == 6)
		display();
}

void Vue_Erosion::display()
{
	clear();
	Vue::afficher();

	cout << "\tParametres: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}
