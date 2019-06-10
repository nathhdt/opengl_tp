#include "controleur.h"


using namespace std;

Controleur::Controleur()
	: Sujet(), ecran(0), objetImage()
{
}

void Controleur::modifierEcran(const int& value)
{
	//On v�rifie que la valeur est bien comprise dans les possibilit�s de menus � afficher
	if (value >= 0 && value <= 9)
	{
		ecran = value;
	}

	notify();
}

int Controleur::ecranActuel() const
{
	return ecran;
}

void Controleur::chargerImage(string _chemin)
{
	objetImage.charger(_chemin);
}

void Controleur::sauvegarderImage(string _chemin)
{
	objetImage.sauvegarder(_chemin);
}

void Controleur::filtreMedian(int _intensite)
{
	objetImage.filtreMedian(_intensite);
}

void Controleur::filtreGaussien(int _intensite)
{
	objetImage.filtreGaussien(_intensite);
}

void Controleur::calculGradient(int _luminosite)
{
	objetImage.gradient(_luminosite);
}

void Controleur::filtreDilatation(int _niveau)
{
	objetImage.dilatation(_niveau);
}

void Controleur::filtreErosion(int _niveau)
{
	objetImage.erosion(_niveau);
}

void Controleur::filtreCanny(int _niveau)
{
	objetImage.canny(_niveau);
}

void Controleur::filtreSeuillage(int _niveau)
{
	objetImage.seuillage(_niveau);
}

void Controleur::filtreSegmentation(int _niveau)
{
	objetImage.segmentation(_niveau);
}

void Controleur::imageTravail()
{
	objetImage.travail();
}

string Controleur::nomFichier()
{
	//On r�cup�re le chemin d'acc�s de l'image par le biais de son objet
	if (objetImage.nom() == "")
	{
		return "aucune";
	}
	else
	{
		//S�parateur pour chemin d'acc�s (un "\"), double-anti-slash pour que le compilateur comprenne que c'est un seul anti-slash
		char separateur = '\\';
		//D�coupe de la string & renvoie la position du premier caract�re du nom de fichier qu'on cherche dans un entier non-sign�
		size_t decoupe = objetImage.nom().rfind(separateur, objetImage.nom().length());

		//Si il trouve bien le nom de fichier
		//string::npos = -1 (pas de match)
		if (decoupe != string::npos) {
			return(objetImage.nom().substr(decoupe + 1, objetImage.nom().length() - decoupe));
		}
		//S'il ne trouve pas le nom de fichier (normalement quasi-impossible)
		return "?";
	}
}