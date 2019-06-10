#include "controleur.h"


using namespace std;

Controleur::Controleur()
	: Sujet(), ecran(0), objetImage()
{
}

void Controleur::modifierEcran(const int& value)
{
	//On vérifie que la valeur est bien comprise dans les possibilités de menus à afficher
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

void Controleur::chargerImage(const string _chemin)
{
	objetImage.charger(_chemin);
}

void Controleur::sauvegarderImage(const string _chemin)
{
	objetImage.sauvegarder(_chemin);
}

void Controleur::filtreMedian(const int _intensite)
{
	objetImage.median(_intensite);
}

void Controleur::filtreGaussien(const int _intensite)
{
	objetImage.gaussien(_intensite);
}

void Controleur::calculGradient(const int _luminosite)
{
	objetImage.gradient(_luminosite);
}

void Controleur::filtreDilatation(const int _niveau)
{
	objetImage.dilatation(_niveau);
}

void Controleur::filtreErosion(const int _niveau)
{
	objetImage.erosion(_niveau);
}

void Controleur::filtreCanny(const int _niveau)
{
	objetImage.canny(_niveau);
}

void Controleur::filtreSeuillage(const int _niveau)
{
	objetImage.seuillage(_niveau);
}

void Controleur::filtreSegmentation(const int _niveau)
{
	objetImage.segmentation(_niveau);
}

void Controleur::imageTravail()
{
	objetImage.travail();
}

string Controleur::nomFichier()
{
	//On récupère le chemin d'accès de l'image par le biais de son objet
	if (objetImage.nom() == "")
	{
		return "aucune";
	}
	else
	{
		//Séparateur pour chemin d'accès (un "\"), double-anti-slash pour que le compilateur comprenne que c'est un seul anti-slash
		char separateur = '\\';
		//Découpe de la string & renvoie la position du premier caractère du nom de fichier qu'on cherche dans un entier non-signé
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