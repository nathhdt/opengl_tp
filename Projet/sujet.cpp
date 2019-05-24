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
	for (int iObserver = 0; iObserver < observateurs.size(); ++iObserver)
	{
		observateurs[iObserver]->notify();
	}
}