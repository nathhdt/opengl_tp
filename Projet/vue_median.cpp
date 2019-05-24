#include "vue_median.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>


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
	int parametre = 0;
	int fini = 0;
	while (fini == 0)
	{
		Vue::afficher();
		COORD coord;

		//Affichage ProgressBar
		cout << "\tIntensite: " << endl << "\t\t";
		cout << endl << "                                                                                                                      " << endl << "\t\t";
		coord.X = 12;
		coord.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
		for (int i = 0; i <= parametre; i++)
		{
			cout << " ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);

		//D�tection de l'appui de touches
		int killer = 0;
		int touche = 0;
		while (killer == 0)
		{
			switch ((touche = _getch())) {
			case 13: //ENTREE
				//TO-DO: application filtre
				appControleur.modifierEcran(0);
				fini = 1;
				killer = 1;
				break;
			case 75: //GAUCHE
				if (parametre != 0)
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

		//Modification coordonn�es curseur (pour �viter de clear() � chaque pression de touche fl�ch�e et faire scintiller l'�cran)
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}