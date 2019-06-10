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
	//Conversion intensit�
	int niveau = (_intensite*2.5);
	if ((niveau % 2) == 0) { niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	medianBlur(img, imageTravaillee, niveau);
}

void image::filtreGaussien(int _intensite)
{
	//Conversion intensit�
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
		//On �crit l'image travaill�e
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

	//On r�cup�re le chemin d'acc�s de l'image (pour le titre de la fen�tre)
	if (nom() == "")
	{
		nomImage = "?";
	}
	else
	{
		//S�parateur pour chemin d'acc�s (un "\"), double-anti-slash pour que le compilateur comprenne que c'est un seul anti-slash
		char separateur = '\\';
		//D�coupe de la string & renvoie la position du premier caract�re du nom de fichier qu'on cherche dans un entier non-sign�
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
	
	//Impossible de faire un resize de la fen�tre par l'utilisateur sans Qt (fais chier)
	namedWindow(nomImage, WINDOW_AUTOSIZE);
	imshow(nomImage, imageTravaillee);

	//Emp�che la fen�tre de se fermer
	while (true)
	{
		waitKey(0);
	}
}

image::~image()
{
}