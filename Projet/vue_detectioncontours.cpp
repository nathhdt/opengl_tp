#include "vue_detectioncontours.h"
#include <iostream>


using namespace std;

Vue_DetectionContours::Vue_DetectionContours(Controleur& _controleur)
	: Vue("APPLICATION D'UN DETECTEUR DE CONTOURS (CANNY)"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_DetectionContours::notify()
{
	if (appControleur.ecranActuel() == 7)
		display();
}

void Vue_DetectionContours::display()
{
	clear();
	Vue::afficher();

	cout << "\tParametres: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}
