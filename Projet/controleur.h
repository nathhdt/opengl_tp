#pragma once
#include "sujet.h"
#include "image.h"


class Controleur : public Sujet
{
private:
	//ID de l'�cran affich�
	int ecran;
	//Instance de l'image travaill�e
	image objetImage;
public:
	Controleur();
	void modifierEcran(const int& value);
	int ecranActuel() const;
	void chargerImage(string _chemin);
	void sauvegarderImage(string _chemin);
	string nomFichier();
};