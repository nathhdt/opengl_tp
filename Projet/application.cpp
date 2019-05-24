#include "application.h"


Application::Application()
	: appControleur(), appVueMenu(appControleur), appVueMedian(appControleur), appVueGaussien(appControleur), appVueGradient(appControleur), appVueDilatation(appControleur), appVueErosion(appControleur), appVueDetectionContours(appControleur), appVueSeuillage(appControleur), appVueSegmentation(appControleur)
{
}

void Application::demarrer()
{
	appControleur.notify();
}