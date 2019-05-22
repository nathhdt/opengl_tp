#include "controleur.h"


Controleur::Controleur()
	: Sujet(), ecran(0)
{
	//TODO
}

void Controleur::modifierEcran(const int& value)
{
	if (value >= 0 && value <= 9)
		ecran = value;

	notify();
}

int Controleur::ecranActuel()
{
	return ecran;
}

//const Complaints& Controleur::getComplaints()
//{
//	return complaints;
//}

//void Controleur::addComplaint(const Complaint& complaint)
//{
//	complaints.add(complaint);
//
	//TODO
//	modifierEcran(0);
//}

//void Controleur::removeComplaint(const int& index)
//{
//	complaints.remove(index);
//	notify();
//}