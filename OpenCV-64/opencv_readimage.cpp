
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>



using namespace cv;
using namespace std;


int main(int argc, const char** argv)
{
	Mat img = imread("tiger.jpg", CV_LOAD_IMAGE_UNCHANGED);
	string name = "Noah";
	Size size = img.size();
	fstream file1("file.txt", ios::out);
	if (img.empty())
	{
		cout << "Error : Image cannot be loaded....." << endl;
		return -1;
	}
	namedWindow("MYWINDOW", CV_WINDOW_AUTOSIZE);
	imshow("MYWINDOW", img);

	waitKey(0);

	cvvDestroyWindow("MYWINDOW");
	cout << name << endl;
	cout << size << endl;
	file1 << size << endl;
	file1 << img.type() << endl;
	//file1 << img.at<Vec3b>(16, 15)[0] << endl;
	file1 << endl;
	file1 << endl;
	file1 << img << endl;
	file1.close();

	return 0;
}