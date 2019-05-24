#include "vue_seuillage.h"
#include <iostream>


using namespace std;

Vue_Seuillage::Vue_Seuillage(Controleur& _controleur)
	: Vue("OPERATIONS DE SEUILLAGE"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Seuillage::notify()
{
	if (appControleur.ecranActuel() == 8)
		display();
}

void Vue_Seuillage::display()
{
	clear();
	Vue::afficher();

	cout << "\tParametres: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}