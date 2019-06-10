#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


using namespace std;

class Vue_Menu : public Vue
{
private:
	Controleur& appControleur;
	int menuSurbrillance;
	int grayScaleApplique;
public:
	Vue_Menu(Controleur& _controleur);
	virtual void notify();
	virtual void display();
	string selectionFichier();
	string selectionEnregistrement() const;
	void afficherImage();
};