#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Median : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Median(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};