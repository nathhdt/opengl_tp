#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Charger : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Charger(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};