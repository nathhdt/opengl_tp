#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Segmentation : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Segmentation(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};