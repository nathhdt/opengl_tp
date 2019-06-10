#include "image.h"
#include <Windows.h>


using namespace cv;

image::image()
	: imageOriginale(), imageTravaillee(), chemin("")
{
}

void image::charger(string _chemin)
{
	if (_chemin == "PAS_DE_FICHIER")
	{
		//L'utilsateur a fait "Annuler", on ne fait rien.
	}
	else
	{
		imageOriginale = imread(_chemin);
		imageTravaillee = imageOriginale;

		//Si l'image est vide
		if (imageOriginale.empty()) {
			MessageBox(NULL, "Impossible de charger l'image (vide)", "Erreur", MB_ICONEXCLAMATION);
		}
		else
		{
			chemin = _chemin;
		}
	}
}

void image::filtreMedian(int _intensite)
{
	//Conversion intensité
	int niveau = (_intensite*2.5);
	if ((niveau % 2) == 0) { niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	medianBlur(img, imageTravaillee, niveau);
}

void image::filtreGaussien(int _intensite)
{
	//Conversion intensité
	int niveau = (_intensite*2.5);
	if ((niveau % 2) == 0) { niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	GaussianBlur(img, imageTravaillee, Size(niveau, niveau), (0.0), 0);
}

void image::sauvegarder(string _chemin)
{
	if (_chemin == "PAS_DE_FICHIER")
	{
		//L'utilsateur a fait "Annuler", on ne fait rien.
	}
	else
	{
		//On écrit l'image travaillée
		imwrite(_chemin, imageTravaillee);
	}
}

string image::nom()
{
	return chemin;
}

void image::travail()
{
	string nomImage = "";

	//On récupère le chemin d'accès de l'image (pour le titre de la fenêtre)
	if (nom() == "")
	{
		nomImage = "?";
	}
	else
	{
		//Séparateur pour chemin d'accès (un "\"), double-anti-slash pour que le compilateur comprenne que c'est un seul anti-slash
		char separateur = '\\';
		//Découpe de la string & renvoie la position du premier caractère du nom de fichier qu'on cherche dans un entier non-signé
		size_t decoupe = nom().rfind(separateur, nom().length());

		//Si il trouve bien le nom de fichier
		//string::npos = -1 (pas de match)
		if (decoupe != string::npos) {
			nomImage = nom().substr(decoupe + 1, nom().length() - decoupe);
		}
		else
		{
			//S'il ne trouve pas le nom de fichier (normalement quasi-impossible)
			nomImage = "?";
		}
	}
	
	//Impossible de faire un resize de la fenêtre par l'utilisateur sans Qt (fais chier)
	namedWindow(nomImage, WINDOW_AUTOSIZE);
	imshow(nomImage, imageTravaillee);

	//Empêche la fenêtre de se fermer
	while (true)
	{
		waitKey(0);
	}
}

image::~image()
{
}