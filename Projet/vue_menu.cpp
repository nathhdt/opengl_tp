#include "vue_menu.h"
#include <conio.h>
#include <iostream>
#include <thread>
#include <Windows.h>


using namespace std;

Vue_Menu::Vue_Menu(Controleur& _controleur)
	: Vue("Traitement OpenCV (TP C++ ESIREM)"), appControleur(_controleur), menuSurbrillance(1), grayScaleApplique(0)
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
		//Si aucune image chargée, on grise le menu
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
				if (grayScaleApplique == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 200);
					cout << "\t\t4. Calcul du gradient dans une image (Sobel)" << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
				}
				else
				{
					cout << "\t\t4. Calcul du gradient dans une image (Sobel)" << endl << endl;
				}
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
				if (grayScaleApplique == 1)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 200);
					cout << "\t\t7. Application d'un detecteur de contours (Canny)" << endl << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 199);
				}
				else
				{
					cout << "\t\t7. Application d'un detecteur de contours (Canny)" << endl << endl;
				}
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

			//Affichage image en cours
			thread affichage(&Vue_Menu::afficherImage, this);
			affichage.detach();

			//Détection de l'appui de touches
			while (killer == 0)
			{
				switch ((touche = _getch())) {
				case 13:
					if (menuSurbrillance != 11 && menuSurbrillance != 1 && menuSurbrillance != 10 && menuSurbrillance != 4 && menuSurbrillance != 7)
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
					else if (menuSurbrillance == 4 || menuSurbrillance == 7)
					{
						grayScaleApplique = 1;
						menuSurbrillance--;
						appControleur.modifierEcran(menuSurbrillance + 1);
					}
					else
					{
						throw string("EXIT_APP");
					}
					killer = 1;
					break;
				case 72:
					//Evite de faire certains filtres qui buggent entre eux
					if (menuSurbrillance == 8 && grayScaleApplique == 1)
					{
						menuSurbrillance = menuSurbrillance - 2;
					}
					else if (menuSurbrillance == 5 && grayScaleApplique == 1)
					{
						menuSurbrillance = menuSurbrillance - 2;
					}
					else if (menuSurbrillance != 1)
					{
						menuSurbrillance--;
					}
					killer = 1;
					break;
				case 80:
					//Evite de faire certains filtres qui buggent entre eux
					if (menuSurbrillance == 6 && grayScaleApplique == 1)
					{
						menuSurbrillance = menuSurbrillance + 2;
					}
					else if (menuSurbrillance == 3 && grayScaleApplique == 1)
					{
						menuSurbrillance = menuSurbrillance + 2;
					}
					else if (menuSurbrillance != 11)
					{
						menuSurbrillance++;
					}
					killer = 1;
					break;
				}
			}
		}
		else //Si aucun fichier n'a été chargé, le menu est restreint
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
	
			//Détection de l'appui de touches
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

		//Modification coordonnées curseur (pour éviter de clear() à chaque pression de touche fléchée et faire scintiller l'écran)
		coord.X = 0;
		coord.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}

string Vue_Menu::selectionFichier()
{
	//Déclare une structure OPENFILENAME
	OPENFILENAME ouvertureFichier;
	//Contient le chemin
	char cheminImage[256];
	//Remplit l'adresse &ouvertureFichier de 0 avec la taille de ouvertureFichier (évite les bugs, memset à utiliser si appli. multi-OS)
	ZeroMemory(&ouvertureFichier, sizeof(ouvertureFichier));
	//Reçoit la taille de la structure
	ouvertureFichier.lStructSize = sizeof(ouvertureFichier);
	ouvertureFichier.lpstrTitle = "Sélectionner une image";
	//Le chemin de l'image sera enregistré dans le char cheminImage
	ouvertureFichier.lpstrFile = cheminImage;
	//Evite un bug de chemin d'accès pour l'image sélectionnée
	ouvertureFichier.lpstrFile[0] = '\0';
	//Reçoit la taille du tableau reçevant le chemin d'accès
	ouvertureFichier.nMaxFile = sizeof(cheminImage);
	//Filtre fichier à sélectionner
	ouvertureFichier.lpstrFilter = "Toutes les images (*.bmp, *.dib, *.jpeg, *.jpg, *.jpe, *.jp2, *.png, *.pbm, *.pgm, *.ppm, *.sr, *.ras, *.tiff, *.tif)\0*.bmp;*.dib;*.jpeg;*.jpg;*.jpe;*.jp2;*.png;*.pbm;*.pgm;*.ppm;*.sr;*.ras;*.tiff;*.tif\0";
	int retour = GetOpenFileName(&ouvertureFichier);
	//Si l'utilisateur a appuyé sur "Annuler" (cf. image.Cpp)
	if (retour == 0)
	{
		return "PAS_DE_FICHIER";
	}
	else
	{
		grayScaleApplique = 0;
		//Conversion du tableau avec le chemin d'accès en string
		string chemin(cheminImage);
		return chemin; //Retourne le chemin complet de l'image à charger
	}
	
}

string Vue_Menu::selectionEnregistrement() const
{
	//Déclare une structure OPENFILENAME
	OPENFILENAME sauvegardeFichier;
	//Contient le chemin
	char cheminImage[256];
	//Remplit l'adresse &ouvertureFichier de 0 avec la taille de sauvegardeFichier (évite les bugs, memset à utiliser si appli. multi-OS)
	ZeroMemory(&sauvegardeFichier, sizeof(sauvegardeFichier));
	//Reçoit la taille de la structure
	sauvegardeFichier.lStructSize = sizeof(sauvegardeFichier);
	sauvegardeFichier.lpstrTitle = "Enregistrer l'image";
	//Le chemin de l'image sera enregistré dans le char cheminImage
	sauvegardeFichier.lpstrFile = cheminImage;
	//Evite un bug de chemin d'accès
	sauvegardeFichier.lpstrFile[0] = '\0';
	//Reçoit la taille du tableau reçevant le chemin d'accès
	sauvegardeFichier.nMaxFile = sizeof(cheminImage);
	//Filtre fichier à enregistrer
	sauvegardeFichier.lpstrFilter = "Toutes les images (*.bmp, *.dib, *.jpeg, *.jpg, *.jpe, *.jp2, *.png, *.pbm, *.pgm, *.ppm, *.sr, *.ras, *.tiff, *.tif)\0*.bmp;*.dib;*.jpeg;*.jpg;*.jpe;*.jp2;*.png;*.pbm;*.pgm;*.ppm;*.sr;*.ras;*.tiff;*.tif\0";
	int retour = GetSaveFileName(&sauvegardeFichier);
	//Si l'utilisateur a appuyé sur "Annuler" (cf. image.Cpp)
	if (retour == 0)
	{
		return "PAS_DE_FICHIER";
	}
	//Conversion du tableau avec le chemin d'accès en string
	string chemin(cheminImage);
	return chemin; //Retourne le chemin complet de l'image à sauvegarder
}

void Vue_Menu::afficherImage()
{
	appControleur.imageTravail();
}