#pragma once
#include "controleur.h"
#include "vue_menu.h"
#include "vue_median.h"
#include "vue_gaussien.h"
#include "vue_gradient.h"
#include "vue_dilatation.h"
#include "vue_erosion.h"
#include "vue_detectioncontours.h"
#include "vue_seuillage.h"
#include "vue_segmentation.h"


class Application
{
private:
	Controleur appControleur;
	Vue_Menu appVueMenu;
	Vue_Median appVueMedian;
	Vue_Gaussien appVueGaussien;
	Vue_Gradient appVueGradient;
	Vue_Dilatation appVueDilatation;
	Vue_Erosion appVueErosion;
	Vue_DetectionContours appVueDetectionContours;
	Vue_Seuillage appVueSeuillage;
	Vue_Segmentation appVueSegmentation;
public:
	Application();
	void demarrer();
};