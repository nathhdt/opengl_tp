#include "image.h"
#include <Windows.h>


using namespace cv;

image::image()
	: imageOriginale(), imageTravaillee(), chemin("")
{
}

void image::charger(const string _chemin)
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
	//On ferme toutes les fen�tres pour laisser place � la nouvelle image
	destroyAllWindows();
}

void image::median(const int _intensite)
{
	//Conversion intensit�
	int niveau = (_intensite*2.5);
	if ((niveau % 2) == 0) { niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	medianBlur(img, imageTravaillee, niveau);
}

void image::gaussien(const int _intensite)
{
	//Conversion intensit�
	int niveau = (_intensite*2.5);
	if ((niveau % 2) == 0) { niveau++; }

	//Travail
	Mat& img = imageTravaillee;
	GaussianBlur(img, imageTravaillee, Size(niveau, niveau), (0.0), 0);
}

void image::gradient(const int _luminosite)
{
	//D�clarations du filtre
	Mat& img = imageTravaillee;
	Mat gradient, gray_img, gradientx, gradienty, final_gradientx, final_gradienty;

	//Travail
	cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
	Sobel(gray_img, gradientx, CV_16S, 1, 0, 3, 1, _luminosite);
	convertScaleAbs(gradientx, final_gradientx);
	Sobel(gray_img, gradienty, CV_16S, 0, 1, 3, 1, _luminosite);
	convertScaleAbs(gradienty, final_gradienty);
	addWeighted(final_gradientx, 0.5, final_gradienty, 0.5, 0, gradient);
	
	//Application des modifications � l'image travaill�e
	imageTravaillee = gradient;
}

void image::dilatation(const int _niveau)
{
	//Conversion niveau
	int convert = _niveau / 3;
	if (convert % 2 == 0) { convert++; }

	//Travail
	Mat& img = imageTravaillee;
	Mat dilated;
	int forme = MORPH_ELLIPSE;
	Mat structure = getStructuringElement(forme, Size(convert, convert), Point(0, 0));
	dilate(img, dilated, structure);
	imageTravaillee = dilated;
}

void image::erosion(const int _niveau)
{
	//Conversion niveau
	int convert = _niveau / 3;
	if (convert % 2 == 0) { convert++; }

	//Travail
	Mat& img = imageTravaillee;
	Mat eroded;
	int forme = MORPH_ELLIPSE;
	Mat structure = getStructuringElement(forme, Size(convert, convert), Point(0, 0));
	erode(img, eroded, structure);
	imageTravaillee = eroded;
}

void image::canny(const int _niveau)
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

void image::seuillage(const int _niveau)
{
	//Conversion niveau
	int valeur_thresold = (40 - (_niveau / 2))*(255 / 40);

	//Travail
	Mat& img = imageTravaillee;
	Mat grayimage, truncated;
	threshold(img, truncated, valeur_thresold, 255, 2);
	imageTravaillee = truncated;
}

void image::segmentation(const int _niveau)
{
	//D�pendances du filtre
	Mat noise;
	Mat edges;
	Mat threshold1;
	Mat distance;
	Mat distance_8bits;
	Mat segmented;

	//PROCEDE
	Mat& img = imageTravaillee;
	//On applque un kernel qui repr�sente une d�riv�e, �a nous montre le "bruit" de l'image
	Mat noyau = (Mat_<float>(3, 3) <<
		1, 1, 1,
		1, -8, 1,
		1, 1, 1);
	//Convolution du kernel et de l'image
	filter2D(img, noise, CV_32F, noyau);
	//D�tection des bords les plus marqu�s
	img.convertTo(edges, CV_32F);
	//On cr�e une image avec de tr�s forts bords et peu de bruit, pour la traiter plus tard
	Mat imgResult = edges - noise;
	//On redonne � l'image sa couleur
	imgResult.convertTo(imgResult, CV_8UC3);
	//Les lignes suivantes: on cr�e des marqueurs pour segmenter l'image avec watershed() (plus tard)
	//On remet la couleur � l'image aux bords marqu�s
	edges.convertTo(edges, CV_8UC3);
	//On met l'image en gris pour le "distance processing"
	cvtColor(imgResult, threshold1, COLOR_BGR2GRAY);
	//Op�ration de seuillage pour r�duire le bruit
	threshold(threshold1, threshold1, (200 / (_niveau + 1)), 255, THRESH_BINARY | THRESH_OTSU);
	//Calcul de la distance pour chaque pixel par rapport au bord le plus proche
	distanceTransform(threshold1, distance, DIST_L2, 3);
	//normalize() donne � l'image un encodage qu'on peut visualiser au lieu d'une matrice remplie de nombres
	normalize(distance, distance, 0, 1.0, NORM_MINMAX);
	//Usage de thresold() pour obtenir nos marqueurs correspondant aux valeurs maximales
	threshold(distance, distance, 0.4, 1.0, THRESH_BINARY);
	//Dilatation de l'image pour un r�sultat plus "smooth"
	Mat kernel1 = Mat::ones(3, 3, CV_8U);
	dilate(distance, distance, kernel1);
	//Conversion en 8 bits
	distance.convertTo(distance_8bits, CV_8U);
	//Usage de fndConturs() pour d�terminer o� segmenter l'image
	vector<vector<Point> > contours;
	findContours(distance_8bits, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//On cr�e une nouvelle image o� l'on placera les marqueurs (encodage 32S pour application math�matique)
	Mat markers = Mat::zeros(distance.size(), CV_32S);
	//On dessine les marqueurs du premier plan
	for (size_t i = 0; i < contours.size(); i++)
	{
		drawContours(markers, contours, static_cast<int>(i), Scalar(static_cast<int>(i) + 1), -1);
	}
	//On dessine les marqueurs de l'arri�re-plan
	circle(markers, Point(5, 5), 3, Scalar(255), -1);
	//On applique le watershed()
	watershed(imgResult, markers);
	//Reconversion de l'image pour visualisation
	markers.convertTo(segmented, CV_8U);
	//On inverse tous les pixels (leurs valeurs) de l'image
	bitwise_not(segmented, segmented);

	//"segmented" est le r�sultat du proc�d� entier (seul param�tre modifiable ici sera le thresold, seuillage)
	imageTravaillee = segmented;
}

void image::sauvegarder(string _chemin)
{
	if (_chemin == "PAS_DE_FICHIER")
	{
		//L'utilsateur a fait "Annuler", on ne fait rien.
	}
	else
	{
		//Si y'a pas de point (pas d'extension), on rajoute PNG par d�faut
		if (_chemin.find(".") == std::string::npos) {

			_chemin = _chemin + ".png";
		}

		//On �crit l'image travaill�e
		imwrite(_chemin, imageTravaillee);
	}
}

string image::nom() const
{
	return chemin;
}

void image::travail()
{
	string nomImage = "";

	//On r�cup�re le chemin d'acc�s de l'image (pour le titre de la fen�tre)
	if (nom() == "")
	{
		nomImage = "?";
	}
	else
	{
		//S�parateur pour chemin d'acc�s (un "\"), double-anti-slash pour que le compilateur comprenne que c'est un seul anti-slash
		char separateur = '\\';
		//D�coupe de la string & renvoie la position du premier caract�re du nom de fichier qu'on cherche dans un entier non-sign�
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
	
	//Impossible de faire un resize de la fen�tre par l'utilisateur sans Qt (fais chier)
	//Impossible de modifier les boutons de contr�le de la fen�tre sans Qt (on peut la fermer...)
	namedWindow(nomImage, WINDOW_AUTOSIZE);
	imshow(nomImage, imageTravaillee);

	//Emp�che la fen�tre de se fermer
	while (true)
	{
		waitKey(0);
	}
}

image::~image()
{
}