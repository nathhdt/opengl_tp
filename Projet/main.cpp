#include "application.h"


using namespace std;

int main()
{
	Application application;
	try
	{
		application.demarrer();
	}
	catch (const string erreur)
	{
		//Une erreur est throw pendant le code si on veut quitter, on quitte proprement par le main (pas de std::exit)
		//On d�truit aussi tous les objets de mani�re propre et efficace
		if (erreur == "EXIT_APP") //Throw dans vue_menu.cpp
		{
			return EXIT_SUCCESS;
		}
	}
}