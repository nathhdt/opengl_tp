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
	void charger(string _chemin);
	void filtreMedian(int _intensite);
	void filtreGaussien(int _intensite);
	void sauvegarder(string _chemin);
	string nom();
	~image();
};