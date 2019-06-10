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
public:
	Vue_Menu(Controleur& _controleur);
	virtual void notify();
	virtual void display();
	string selectionFichier() const;
	string selectionEnregistrement() const;
	void afficherImage();
};