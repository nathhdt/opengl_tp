#include "vue_menu.h"
#include <iostream>


using namespace std;

Vue_Menu::Vue_Menu(Controleur& _controleur)
	: Vue("Traitement OpenCV (TP C++ ESIREM)"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Menu::notify()
{
	if (appControleur.ecranActuel() == 0)
		display();
}

void Vue_Menu::display()
{
	clear();
	Vue::afficher();

	cout << "\tIMAGE CHARGEE: aucune" << endl;
	cout << "\t\t1. Charger une image" << endl << endl;
	cout << "\tFILTRES" << endl;
	cout << "\t\t2. Filtre median" << endl;
	cout << "\t\t3. Filtre gaussien" << endl << endl;
	cout << "\tDERIVATION" << endl;
	cout << "\t\t4. Calcul du gradient dans une image (Sobel)" << endl << endl;
	cout << "\tOPERATIONS DE MORPHOLOGIE MATHEMATIQUE" << endl;
	cout << "\t\t5. Dilatation" << endl;
	cout << "\t\t6. Erosion" << endl << endl;
	cout << "\tDETECTION DE CONTOURS" << endl;
	cout << "\t\t7. Application d'un detecteur de contours (Canny)" << endl << endl;
	cout << "\tSEGMENTATIONS D'IMAGES" << endl;
	cout << "\t\t8. Operations de seuillage" << endl;
	cout << "\t\t9. Segmentation par croissance de region" << endl << endl;
	cout << "\t10. Quitter" << endl << endl << "\t";
	int reponse;
	cin.clear();
	cin >> reponse;

	appControleur.modifierEcran(reponse);
}
