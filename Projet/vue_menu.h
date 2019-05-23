#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Menu : public Vue
{
private:
	Controleur& appControleur;
	int menuSurbrillance;
public:
	Vue_Menu(Controleur& _controleur);
	virtual void notify();
	virtual void display();
	void chargerImage();
};