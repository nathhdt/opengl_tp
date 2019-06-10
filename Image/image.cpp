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

//INFO: _intensite doit etre supérieur à 1 et être impair (1 = 10%, 5 = 50%.. on va jusqu'à 21 = 210%)
void image::filtreMedian(int _intensite)
{
}

//INFO: sigma à 0, le reste pareil que le filtre médian
void image::filtreGaussien(int _intensite)
{
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


image::~image()
{
}