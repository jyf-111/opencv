#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("D:\\Pictures\\Saved Pictures\\DCS.png");
	cvtColor(img, img, COLOR_BGR2GRAY);
	resize(img, img, Size(img.cols / 2, img.rows/2));
	imshow("gray", img);
	equalizeHist(img, img);
	imshow("equalizeHist", img);
	waitKey(0);
}