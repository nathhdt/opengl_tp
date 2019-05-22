#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Gradient : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Gradient(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};