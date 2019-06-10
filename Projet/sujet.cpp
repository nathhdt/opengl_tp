#include "sujet.h"


Sujet::Sujet()
{
}

void Sujet::ajouterObservateur(Observateur* observateur)
{
	observateurs.push_back(observateur);
}

void Sujet::notify()
{
	//notify() pour tous les sujets
	for (int i = 0; i < observateurs.size(); i++)
	{
		observateurs[i]->notify();
	}
}