#include "vue_menu.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>


using namespace std;

Vue_Menu::Vue_Menu(Controleur& _controleur)
	: Vue("Traitement OpenCV (TP C++ ESIREM)"), appControleur(_controleur), menuSurbrillance(1)
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

	//Cacher curseur
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);

	//BOUCLE PRINCIPALE DU MENU
	int touche = 0;
	int killer = 0;
	while (true)
	{
		Vue::afficher();
		touche = 0;
		killer = 0;

		//Affichage menu
		cout << "\tIMAGE CHARGEE: aucune" << endl;
		if (menuSurbrillance == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t1. Charger une image" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t1. Charger une image" << endl << endl;
		}
		cout << "\tFILTRES" << endl;
		if (menuSurbrillance == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t2. Filtre median" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t2. Filtre median" << endl;
		}
		if (menuSurbrillance == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t3. Filtre gaussien" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t3. Filtre gaussien" << endl << endl;
		}
		cout << "\tDERIVATION" << endl;
		if (menuSurbrillance == 4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t4. Calcul du gradient dans une image (Sobel)" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t4. Calcul du gradient dans une image (Sobel)" << endl << endl;
		}
		cout << "\tOPERATIONS DE MORPHOLOGIE MATHEMATIQUE" << endl;
		if (menuSurbrillance == 5)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t5. Dilatation" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t5. Dilatation" << endl;
		}
		if (menuSurbrillance == 6)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t6. Erosion" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t6. Erosion" << endl << endl;
		}
		cout << "\tDETECTION DE CONTOURS" << endl;
		if (menuSurbrillance == 7)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t7. Application d'un detecteur de contours (Canny)" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t7. Application d'un detecteur de contours (Canny)" << endl << endl;
		}
		cout << "\tSEGMENTATIONS D'IMAGES" << endl;
		if (menuSurbrillance == 8)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t8. Operations de seuillage" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t8. Operations de seuillage" << endl;
		}
		if (menuSurbrillance == 9)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t9. Segmentation par croissance de region" << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t9. Segmentation par croissance de region" << endl << endl;
		}
		if (menuSurbrillance == 10)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
			cout << "\t\t10. Quitter" << endl << endl << "\t";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
		}
		else
		{
			cout << "\t\t10. Quitter" << endl << endl << "\t";
		}

		//Détection touches
		while (killer == 0)
		{
			switch ((touche = _getch())) {
			case 13:
				if (menuSurbrillance != 10 && menuSurbrillance != 1)
				{
					appControleur.modifierEcran(menuSurbrillance);
				}
				else if (menuSurbrillance == 1)
				{
					chargerImage();
				}
				else
				{
					throw string("EXITAPP");
				}
				killer = 1;
				break;
			case 72:
				if (menuSurbrillance != 1)
				{
					menuSurbrillance--;
				}
				killer = 1;
				break;
			case 80:
				if (menuSurbrillance != 10)
				{
					menuSurbrillance++;
				}
				killer = 1;
				break;
			}
		}

		//Modification coordonnées curseur (pour éviter de clear() à chaque pression de touche fléchée)
		COORD coord;
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}

void Vue_Menu::chargerImage()
{
	OPENFILENAME ouvertureFichier;
	char szFile[100];
	ZeroMemory(&ouvertureFichier, sizeof(ouvertureFichier));
	ouvertureFichier.lStructSize = sizeof(ouvertureFichier);
	ouvertureFichier.hwndOwner = NULL;
	ouvertureFichier.lpstrTitle = "Sélectionnez une image";
	ouvertureFichier.lpstrFile = szFile;
	ouvertureFichier.lpstrFile[0] = '\0';
	ouvertureFichier.nMaxFile = sizeof(szFile);
	ouvertureFichier.lpstrFilter = "Toutes les images (*.bmp, *.dib, *.jpeg, *.jpg, *.jpe, *.jp2, *.png, *.pbm, *.pgm, *.ppm, *.sr, *.ras, *.tiff, *.tif)\0*.bmp;*.dib;*.jpeg;*.jpg;*.jpe;*.jp2;*.png;*.pbm;*.pgm;*.ppm;*.sr;*.ras;*.tiff;*.tif\0";
	ouvertureFichier.nFilterIndex = 1;
	ouvertureFichier.lpstrFileTitle = NULL;
	ouvertureFichier.nMaxFileTitle = 0;
	ouvertureFichier.lpstrInitialDir = NULL;
	ouvertureFichier.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	GetOpenFileName(&ouvertureFichier);
	MessageBox(NULL, ouvertureFichier.lpstrFile, "File Name", MB_OK);
}
