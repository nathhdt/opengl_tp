#include "vue_segmentation.h"
#include <iostream>


using namespace std;

Vue_Segmentation::Vue_Segmentation(Controleur& _controleur)
	: Vue("SEGMENTATION PAR CROISSANCE DE REGION"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Segmentation::notify()
{
	if (appControleur.ecranActuel() == 9)
		display();
}

void Vue_Segmentation::display()
{
	clear();
	Vue::afficher();

	cout << "\tParametres: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}