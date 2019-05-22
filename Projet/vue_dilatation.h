#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Dilatation : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Dilatation(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};