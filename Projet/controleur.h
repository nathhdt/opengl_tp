#pragma once
#include "sujet.h"
//#include "complaints.h"


class Controleur : public Sujet
{
private:
	//ID de l'écran affiché
	int ecran;

	//Collection des plaintes
	//Complaints complaints;
public:
	Controleur();
	void modifierEcran(const int& value);
	int ecranActuel();
	//const Complaints& getComplaints();
	//void addComplaint(const Complaint& complaint);
	//void removeComplaint(const int& index);
};