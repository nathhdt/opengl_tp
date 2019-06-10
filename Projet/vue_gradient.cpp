#include "vue_gradient.h"
#include <iostream>


using namespace std;

Vue_Gradient::Vue_Gradient(Controleur& _controleur)
	: Vue("CALCUL DU GRADIENT DANS UNE IMAGE (SOBEL)"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Gradient::notify()
{
	if (appControleur.ecranActuel() == 4)
	{
		display();
	}
}

void Vue_Gradient::display()
{
	clear();
	Vue::afficher();

	cout << "\tParametres: ";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(0);
}