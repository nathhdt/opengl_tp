#include "vue_gaussien.h"
#include <iostream>


using namespace std;

Vue_Gaussien::Vue_Gaussien(Controleur& _controleur)
	: Vue("FILTRE GAUSSIEN"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Gaussien::notify()
{
	if (appControleur.ecranActuel() == 3)
		display();
}

void Vue_Gaussien::display()
{
	clear();
	Vue::afficher();

	cout << "\tParametres: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}
