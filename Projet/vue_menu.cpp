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
	{
		display();
	}
}

void Vue_Menu::display()
{
	clear();

	//Cacher le curseur de la console
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);

	//BOUCLE PRINCIPALE DU MENU
	int touche = 0;
	int killer = 0;
	COORD coord;

	while (true)
	{
		//Si aucune image charg�e, on grise le menu
		if (appControleur.nomFichier() != "aucune")
		{
			Vue::afficher();
			touche = 0;
			killer = 0;
			cout << endl << "                                                                                                                       " << endl;
			coord.X = 0;
			coord.Y = 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << "\tIMAGE CHARGEE: " << appControleur.nomFichier() << endl;
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
				cout << "\t\t10. Sauvegarder" << endl << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
			}
			else
			{
				cout << "\t\t10. Sauvegarder" << endl << "\t";
			}
			if (menuSurbrillance == 11)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
				cout << "\t11. Quitter" << endl << endl << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
			}
			else
			{
				cout << "\t11. Quitter" << endl << endl << "\t";
			}

			//D�tection de l'appui de touches
			while (killer == 0)
			{
				switch ((touche = _getch())) {
				case 13:
					if (menuSurbrillance != 11 && menuSurbrillance != 1 && menuSurbrillance != 10)
					{
						appControleur.modifierEcran(menuSurbrillance);
					}
					else if (menuSurbrillance == 1)
					{
						appControleur.chargerImage(selectionFichier().c_str());
					}
					else if (menuSurbrillance == 10)
					{
						appControleur.sauvegarderImage(selectionEnregistrement());
					}
					else
					{
						throw string("EXIT_APP");
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
					if (menuSurbrillance != 11)
					{
						menuSurbrillance++;
					}
					killer = 1;
					break;
				}
			}
		}
		else //Si aucun fichier n'a �t� charg�, le menu est restreint
		{
			Vue::afficher();
			touche = 0;
			killer = 0;
			cout << endl << "                                                                                                                       " << endl;
			coord.X = 0;
			coord.Y = 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

			cout << "\tIMAGE CHARGEE: " << appControleur.nomFichier() << endl;
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
	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 200);
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
			cout << "\t\t10. Sauvegarder" << endl << "\t";
	
			if (menuSurbrillance == 11)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112);
				cout << "\t11. Quitter" << endl << endl << "\t";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
				cout << "\t11. Quitter" << endl << endl << "\t";
			}
	
			//D�tection de l'appui de touches
			while (killer == 0)
			{
				switch ((touche = _getch())) {
				case 13:
					if (menuSurbrillance == 1)
					{
						appControleur.chargerImage(selectionFichier().c_str());
					}
					else
					{
						throw string("EXIT_APP");
					}
					killer = 1;
					break;
				case 72:
					menuSurbrillance = 1;
					killer = 1;
					break;
				case 80:
					menuSurbrillance = 11;
					killer = 1;
					break;
				}
			}
		}

		//Modification coordonn�es curseur (pour �viter de clear() � chaque pression de touche fl�ch�e et faire scintiller l'�cran)
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}

string Vue_Menu::selectionFichier() const
{
	//D�clare une structure OPENFILENAME
	OPENFILENAME ouvertureFichier;
	//Contient le chemin
	char cheminImage[256];
	//Remplit l'adresse &ouvertureFichier de 0 avec la taille de ouvertureFichier (�vite les bugs, memset � utiliser si appli. multi-OS)
	ZeroMemory(&ouvertureFichier, sizeof(ouvertureFichier));
	//Re�oit la taille de la structure
	ouvertureFichier.lStructSize = sizeof(ouvertureFichier);
	ouvertureFichier.lpstrTitle = "S�lectionner une image";
	//Le chemin de l'image sera enregistr� dans le char cheminImage
	ouvertureFichier.lpstrFile = cheminImage;
	//Evite un bug de chemin d'acc�s pour l'image s�lectionn�e
	ouvertureFichier.lpstrFile[0] = '\0';
	//Re�oit la taille du tableau re�evant le chemin d'acc�s
	ouvertureFichier.nMaxFile = sizeof(cheminImage);
	//Filtre fichier � s�lectionner
	ouvertureFichier.lpstrFilter = "Toutes les images (*.bmp, *.dib, *.jpeg, *.jpg, *.jpe, *.jp2, *.png, *.pbm, *.pgm, *.ppm, *.sr, *.ras, *.tiff, *.tif)\0*.bmp;*.dib;*.jpeg;*.jpg;*.jpe;*.jp2;*.png;*.pbm;*.pgm;*.ppm;*.sr;*.ras;*.tiff;*.tif\0";
	int retour = GetOpenFileName(&ouvertureFichier);
	//Si l'utilisateur a appuy� sur "Annuler" (cf. image.Cpp)
	if (retour == 0)
	{
		return "PAS_DE_FICHIER";
	}
	//Conversion du tableau avec le chemin d'acc�s en string
	string chemin(cheminImage);
	return chemin; //Retourne le chemin complet de l'image � charger
}

string Vue_Menu::selectionEnregistrement() const
{
	//D�clare une structure OPENFILENAME
	OPENFILENAME sauvegardeFichier;
	//Contient le chemin
	char cheminImage[256];
	//Remplit l'adresse &ouvertureFichier de 0 avec la taille de sauvegardeFichier (�vite les bugs, memset � utiliser si appli. multi-OS)
	ZeroMemory(&sauvegardeFichier, sizeof(sauvegardeFichier));
	//Re�oit la taille de la structure
	sauvegardeFichier.lStructSize = sizeof(sauvegardeFichier);
	sauvegardeFichier.lpstrTitle = "Enregistrer l'image";
	//Le chemin de l'image sera enregistr� dans le char cheminImage
	sauvegardeFichier.lpstrFile = cheminImage;
	//Evite un bug de chemin d'acc�s
	sauvegardeFichier.lpstrFile[0] = '\0';
	//Re�oit la taille du tableau re�evant le chemin d'acc�s
	sauvegardeFichier.nMaxFile = sizeof(cheminImage);
	//Filtre fichier � enregistrer
	sauvegardeFichier.lpstrFilter = "Toutes les images (*.bmp, *.dib, *.jpeg, *.jpg, *.jpe, *.jp2, *.png, *.pbm, *.pgm, *.ppm, *.sr, *.ras, *.tiff, *.tif)\0*.bmp;*.dib;*.jpeg;*.jpg;*.jpe;*.jp2;*.png;*.pbm;*.pgm;*.ppm;*.sr;*.ras;*.tiff;*.tif\0";
	int retour = GetSaveFileName(&sauvegardeFichier);
	//Si l'utilisateur a appuy� sur "Annuler" (cf. image.Cpp)
	if (retour == 0)
	{
		return "PAS_DE_FICHIER";
	}
	//Conversion du tableau avec le chemin d'acc�s en string
	string chemin(cheminImage);
	return chemin; //Retourne le chemin complet de l'image � sauvegarder
}