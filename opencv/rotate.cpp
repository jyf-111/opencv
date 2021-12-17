#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("1.jpg");

	int h = img.rows;
	int w = img.cols;

	Mat M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);
	double cos = abs(M.at<double>(0, 0));
	double sin = abs(M.at<double>(0, 1));
	int nw = cos * w + sin * h;
	int nh = sin * w + cos * h;
	M.at<double>(0, 2) += nw / 2 - w / 2;
	M.at<double>(1, 2) += nh / 2 - h / 2;
	warpAffine(img, img, M,Size(nw,nh),INTER_LINEAR,0,Scalar(255,0,0));
	imshow("img", img);
	waitKey(0);
}