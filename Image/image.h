#pragma once
#include <opencv2/opencv.hpp>


using namespace std;

class image
{
private:
	string chemin;
	cv::Mat imageOriginale;
	cv::Mat imageTravaillee;
public:
	image();
	void charger(const string _chemin);
	void median(const int _intensite);
	void gaussien(const int _intensite);
	void gradient(const int _luminosite);
	void dilatation(const int _niveau);
	void erosion(const int _niveau);
	void canny(const int _niveau);
	void seuillage(const int _niveau);
	void segmentation(const int _niveau);
	void sauvegarder(string _chemin);
	string nom() const;
	void travail();
	~image();
};