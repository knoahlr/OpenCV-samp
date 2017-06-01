#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;
using namespace cv;

void colorReduce(Mat image, int div = 64) {

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