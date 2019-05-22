#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Erosion : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Erosion(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};