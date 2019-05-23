#include "application.h"


int main()
{
	Application application;
	try
	{
		application.demarrer();
	}
	catch (const std::string err)
	{
		//Une erreur est throw pendant le code si on veut quitter, on quitte proprement par le main (pas de std::exit)
		if (err == "EXITAPP") //Throw dans vue_menu.cpp
		{
			return EXIT_SUCCESS;
		}
	}
}