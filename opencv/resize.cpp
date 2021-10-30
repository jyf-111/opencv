#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("D:\\Pictures\\Saved Pictures\\1.jpg");
	Mat zoomin, zoomout;
	int h = img.rows;
	int w = img.cols;

	resize(img, zoomin, Size(w / 2, h / 2), INTER_LINEAR);
	resize(img, zoomout, Size(w * 1.5, h * 1.5), INTER_LINEAR);
	imshow("img", img);
	imshow("zoomin", zoomin);
	imshow("zoomout", zoomout);

	waitKey(0);
}