#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat m = imread("D:\\Pictures\\Saved Pictures\\DCS.png");
	Mat dst;
	m.convertTo(dst, CV_32F);
	cout << m.type() << endl;
	cout << dst.type() << endl;

	normalize(dst, dst, 1.0, 0, NORM_MINMAX);
	cout << dst.type() << endl;
	imshow("1",dst);
	waitKey(0);
	return 0;
}