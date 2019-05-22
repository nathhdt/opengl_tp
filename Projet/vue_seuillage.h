#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Seuillage : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Seuillage(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};