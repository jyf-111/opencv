#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat m = imread("D:\\Pictures\\Saved Pictures\\2.jpg"); 
	Mat dst =m;
	namedWindow("img1", WINDOW_AUTOSIZE);
	cvtColor(m, dst, COLOR_BGR2HSV);
	inRange(dst, Scalar(35, 43, 46), Scalar(77, 255, 255), dst);
	dst = ~dst;
	imshow("img1", dst);
	Mat bk = Mat::zeros(m.size(), m.type());
	bk = Scalar(0, 0, 255);

	m.copyTo(bk, dst);
	imshow("img", bk);
	waitKey(0);
	destroyAllWindows();
}