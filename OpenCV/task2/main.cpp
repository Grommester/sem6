#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <string>
#include <cstring>
using namespace cv;
using namespace std;

void my_mouse_callback(int event, int x, int y, int flags, void* param);
int reading(string Filename, string imagename, double wl, double hl, double wr, double hr);
void file();

int main(int argc, char** argv) 
{
	const char* imagename = "kartinka.jpeg";
	const char* traectory_file = "coordinat.txt";
	double wl = 55.639799;
	double hl = 37.828428;
	double wr = 55.622020;
	double hr = 37.873735;
	reading("coordinat.txt", "kartinka.jpeg", wl, hl, wr, hr);
	Mat image = imread("kartinka.jpeg");
	namedWindow("modernGoogle");
	setMouseCallback("modernGoogle", my_mouse_callback, &image);
	while (true) {
		imshow("modernGoogle", image);
		waitKey(30);
	}
	return(0);
}

	void my_mouse_callback(int event, int x, int y, int flags, void* param)
	{
		if (event == EVENT_LBUTTONDOWN)
		{
			Mat* plmage = (Mat*)param;
			Mat image = *plmage;
			circle(image, Point(x, y), 5, Scalar(255, 0, 0), FILLED, 8, 0);
		}
	}





