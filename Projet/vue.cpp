#include "vue.h"
#include <cstdlib>
#include <iostream>


using namespace std;

Vue::Vue(const string& _titre)
	: titre(_titre)
{
}

void Vue::clear() const
{
	//Permet de clear l'écran (vider la console)
	system("cls");
}

void Vue::afficher() const
{
	//Affiche le titre du menu
	cout << titre << endl << endl;
}