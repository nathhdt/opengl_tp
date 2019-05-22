#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Gaussien : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Gaussien(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};