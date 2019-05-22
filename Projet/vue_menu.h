#pragma once
#include "observateur.h"
#include "vue.h"
#include "controleur.h"


class Vue_Menu : public Vue
{
private:
	Controleur& appControleur;
public:
	Vue_Menu(Controleur& _controleur);
	virtual void notify();
	virtual void display();
};