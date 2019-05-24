#include "controleur.h"


using namespace std;

Controleur::Controleur()
	: Sujet(), ecran(0), objetImage()
{
}

void Controleur::modifierEcran(const int& value)
{
	if (value >= 0 && value <= 9)
		ecran = value;

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

string Controleur::nomFichier()
{
	if (objetImage.nom() == "")
	{
		return "aucune";
	}
	else
	{
		char sep = '/';
		#ifdef _WIN32
		sep = '\\';
		#endif
		size_t i = objetImage.nom().rfind(sep, objetImage.nom().length());
		if (i != string::npos) {
			return(objetImage.nom().substr(i + 1, objetImage.nom().length() - i));
		}
		return "?";
	}
}