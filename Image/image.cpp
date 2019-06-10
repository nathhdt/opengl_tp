#include "image.h"
#include <Windows.h>


using namespace cv;

image::image()
	: imageOriginale(), imageTravaillee(), chemin("")
{
}

void image::charger(string _chemin)
{
	if (_chemin == "PAS_DE_FICHIER")
	{
		//L'utilsateur a fait "Annuler", on ne fait rien.
	}
	else
	{
		imageOriginale = imread(_chemin);
		imageTravaillee = imageOriginale;

		//Si l'image est vide
		if (imageOriginale.empty()) {
			MessageBox(NULL, "Impossible de charger l'image (vide)", "Erreur", MB_ICONEXCLAMATION);
		}
		else
		{
			chemin = _chemin;
		}
	}
}

void image::filtreMedian(int _intensite)
{
	//Conversion intensité
	int niveau = (_intensite*2.5);
	if ((niveau % 2) == 0) { niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	medianBlur(img, imageTravaillee, niveau);
}

void image::filtreGaussien(int _intensite)
{
	//Conversion intensité
	int niveau = (_intensite*2.5);
	if ((niveau % 2) == 0) { niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	GaussianBlur(img, imageTravaillee, Size(niveau, niveau), (0.0), 0);
}

void image::gradient(int _luminosite)
{
	//Déclarations du filtre
	Mat& img = imageTravaillee;
	Mat gradient, gray_img, gradientx, gradienty, final_gradientx, final_gradienty;

	//Travail
	cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
	Sobel(gray_img, gradientx, CV_16S, 1, 0, 3, 1, _luminosite);
	convertScaleAbs(gradientx, final_gradientx);
	Sobel(gray_img, gradienty, CV_16S, 0, 1, 3, 1, _luminosite);
	convertScaleAbs(gradienty, final_gradienty);
	addWeighted(final_gradientx, 0.5, final_gradienty, 0.5, 0, gradient);
	
	//Application des modifications à l'image travaillée
	imageTravaillee = gradient;
}

void image::dilatation(int _niveau)
{
	//Conversion niveau
	_niveau = (_niveau / 3);
	if ((_niveau % 2 == 0)) { _niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	Mat dilated;
	int forme = MORPH_ELLIPSE;
	Mat structure = getStructuringElement(forme, Size(_niveau, _niveau), Point(0, 0));
	dilate(img, dilated, structure);
	imageTravaillee = dilated;
}

void image::erosion(int _niveau)
{
	//Conversion niveau
	_niveau = (_niveau / 3);
	if ((_niveau % 2 == 0)) { _niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	Mat eroded;
	int forme = MORPH_ELLIPSE;
	Mat structure = getStructuringElement(forme, Size(_niveau, _niveau), Point(0, 0));
	erode(img, eroded, structure);
	imageTravaillee = eroded;
}

void image::canny(int _niveau)
{
	//Conversion niveau
	int blurlevel = ((15 + (10 / _niveau)) - (_niveau / 4));
	if ((blurlevel % 2) == 0) { blurlevel++; }

	//Travail
	Mat& img = imageTravaillee;
	Mat gray_image, canny_result, blured_image;
	cvtColor(img, gray_image, cv::COLOR_BGR2GRAY);
	blur(gray_image, blured_image, Size(blurlevel, blurlevel));
	Canny(blured_image, canny_result, 0, (40 - _niveau), 3, false);
	imageTravaillee = canny_result;
}

void image::seuillage(int _niveau)
{
	//Conversion niveau
	int valeur_thresold = ((40 - (_niveau / 2))*(255 / 40));

	//Travail
	Mat& img = imageTravaillee;
	Mat grayimage, truncated;
	threshold(img, truncated, valeur_thresold, 255, 2);
	imageTravaillee = truncated;
}

void image::segmentation(int _niveau)
{
	//Setup du filtre
	Mat growth;
	Point point(5, 5);

	//Travail
	Mat& img = imageTravaillee;
	floodFill(img, cv::Point(10, 10), 255, (cv::Rect*)0, cv::Scalar(), 200);

	imageTravaillee = img;
}

void image::sauvegarder(string _chemin)
{
	if (_chemin == "PAS_DE_FICHIER")
	{
		//L'utilsateur a fait "Annuler", on ne fait rien.
	}
	else
	{
		//On écrit l'image travaillée
		imwrite(_chemin, imageTravaillee);
	}
}

string image::nom()
{
	return chemin;
}

void image::travail()
{
	string nomImage = "";

	//On récupère le chemin d'accès de l'image (pour le titre de la fenêtre)
	if (nom() == "")
	{
		nomImage = "?";
	}
	else
	{
		//Séparateur pour chemin d'accès (un "\"), double-anti-slash pour que le compilateur comprenne que c'est un seul anti-slash
		char separateur = '\\';
		//Découpe de la string & renvoie la position du premier caractère du nom de fichier qu'on cherche dans un entier non-signé
		size_t decoupe = nom().rfind(separateur, nom().length());

		//Si il trouve bien le nom de fichier
		//string::npos = -1 (pas de match)
		if (decoupe != string::npos) {
			nomImage = nom().substr(decoupe + 1, nom().length() - decoupe);
		}
		else
		{
			//S'il ne trouve pas le nom de fichier (normalement quasi-impossible)
			nomImage = "?";
		}
	}
	
	//Impossible de faire un resize de la fenêtre par l'utilisateur sans Qt (fais chier)
	namedWindow(nomImage, WINDOW_AUTOSIZE);
	imshow(nomImage, imageTravaillee);

	//Empêche la fenêtre de se fermer
	while (true)
	{
		waitKey(0);
	}
}

image::~image()
{
}