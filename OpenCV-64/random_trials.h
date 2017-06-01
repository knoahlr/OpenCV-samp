
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
using namespace cv;

void colorReduce(Mat image, int div = 64)
{

	int nl = image.rows; // number of lines 
						 // total number of elements per line 
	int nc = image.cols * image.channels();

	for (int j = 0; j<nl; j++) {

		// get the address of row j 
		uchar* data = image.ptr<uchar>(j);

		for (int i = 0; i<nc; i++) {

			// process each pixel --------------------- 

			data[i] = data[i] / div*div + div / 2;

			// end of pixel processing ---------------- 

		} // end of line 
	}
}

string type2str(int type)
{
	string r;

	uchar depth = type & CV_MAT_DEPTH_MASK;
	uchar chans = 1 + (type >> CV_CN_SHIFT);

	switch (depth) {
	case CV_8U:  r = "8U"; break;
	case CV_8S:  r = "8S"; break;
	case CV_16U: r = "16U"; break;
	case CV_16S: r = "16S"; break;
	case CV_32S: r = "32S"; break;
	case CV_32F: r = "32F"; break;
	case CV_64F: r = "64F"; break;
	default:     r = "User"; break;
	}

	r += "C";
	r += (chans + '0');

	return r;
}
