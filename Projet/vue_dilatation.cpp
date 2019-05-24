#include "vue_dilatation.h"
#include <iostream>


using namespace std;

Vue_Dilatation::Vue_Dilatation(Controleur& _controleur)
	: Vue("DILATATION"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Dilatation::notify()
{
	if (appControleur.ecranActuel() == 5)
		display();
}

void Vue_Dilatation::display()
{
	clear();
	Vue::afficher();

	cout << "\tParametres: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}