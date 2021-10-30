#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat img = Mat::zeros(Size(1000, 1000), CV_8UC3);
	img = Scalar(0, 0, 0);
	Point p1(100, 100);
	Point p2(80, 120);
	Point p3(110, 90);
	Point p4(500, 300);
	Point p5(800, 500);
	Point p6(900, 100);
	std::vector<Point> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	polylines(img, v, true, Scalar(255, 255, 255), 2, 8, 0);
	v.pop_back();
	v.pop_back();
	std::vector<std::vector<Point>> contours;
	contours.push_back(v);
	drawContours(img, contours, -1, Scalar(0, 0, 255), 2);

	imshow("img",img);
	waitKey(0);
}