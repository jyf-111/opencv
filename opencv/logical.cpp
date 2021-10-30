#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{

	Mat m1 = Mat::zeros(Size(500,500), CV_8UC3);
	Mat m = Mat::zeros(Size(500, 500), CV_8UC3);
	rectangle(m, Rect(100, 100, 80, 80), Scalar(255, 255, 0),-1,LINE_8,0);
	rectangle(m1, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);
	imshow("img", m);
	imshow("img1", m1);
	Mat dst = Mat::zeros(m.size(), m.type());
	bitwise_and(m, m1,dst);

	dst = ~dst;

	imshow("img2", dst);
	waitKey(0);
	destroyAllWindows();
}