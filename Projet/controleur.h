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
	void chargerImage(const string _chemin);
	void sauvegarderImage(const string _chemin);
	void filtreMedian(const int _intensite);
	void filtreGaussien(const int _intensite);
	void calculGradient(const int _luminosite);
	void filtreDilatation(const int _niveau);
	void filtreErosion(const int _niveau);
	void filtreCanny(const int _niveau);
	void filtreSeuillage(const int _niveau);
	void filtreSegmentation(const int _niveau);
	void imageTravail();
	string nomFichier();
};