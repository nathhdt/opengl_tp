#pragma once
#include "sujet.h"
#include "image.h"


class Controleur : public Sujet
{
private:
	//ID de l'écran affiché
	int ecran;
	//Instance de l'image travaillée
	image objetImage;
public:
	Controleur();
	void modifierEcran(const int& value);
	int ecranActuel() const;
	void chargerImage(string _chemin);
	void sauvegarderImage(string _chemin);
	void filtreMedian(int _intensite);
	void filtreGaussien(int _intensite);
	void calculGradient(int _luminosite);
	void filtreDilatation(int _niveau);
	void imageTravail();
	string nomFichier();
};