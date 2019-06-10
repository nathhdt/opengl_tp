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

//INFO: _intensite doit etre sup�rieur � 1 et �tre impair (1 = 10%, 5 = 50%.. on va jusqu'� 21 = 210%)
void image::filtreMedian(int _intensite)
{
}

//INFO: sigma � 0, le reste pareil que le filtre m�dian
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
		//On �crit l'image travaill�e
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