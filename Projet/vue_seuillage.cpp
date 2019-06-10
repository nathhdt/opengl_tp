#include "vue_seuillage.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>


using namespace std;

Vue_Seuillage::Vue_Seuillage(Controleur& _controleur)
	: Vue("OPERATIONS DE SEUILLAGE"), appControleur(_controleur)
{
	appControleur.ajouterObservateur(this);
}

void Vue_Seuillage::notify()
{
	if (appControleur.ecranActuel() == 8)
	{
		display();
	}
}

void Vue_Seuillage::display()
{
	clear();
	int parametre = 1;
	int fini = 0;
	while (fini == 0)
	{
		Vue::afficher();
		COORD coord;

		//Affichage ProgressBar
		cout << "\tNiveau: " << endl << "\t\t";
		cout << endl << "                                                     |" << endl << "\t\t";
		coord.X = 12;
		coord.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		cout << "|";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		for (int i = 0; i <= parametre - 1; i++)
		{
			cout << " ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);

		//Détection de l'appui de touches
		int killer = 0;
		int touche = 0;
		while (killer == 0)
		{
			switch ((touche = _getch())) {
			case 13: //ENTREE
				cout << endl << endl << "\t    ..." << endl;
				appControleur.filtreSeuillage(parametre);
				appControleur.modifierEcran(0);
				fini = 1;
				killer = 1;
				break;
			case 75: //GAUCHE
				if (parametre != 1)
				{
					parametre--;
				}
				killer = 1;
				break;
			case 77: //DROITE
				if (parametre != 40)
				{
					parametre++;
				}
				killer = 1;
				break;
			}
		}

		//Modification coordonnées curseur (pour éviter de clear() à chaque pression de touche fléchée et faire scintiller l'écran)
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}