#pragma once
#include <vector>
#include "observateur.h"


class Sujet
{
private:
	std::vector<Observateur*> observateurs;
public:
	Sujet();
	void ajouterObservateur(Observateur* _observateur);
	void notify();
};