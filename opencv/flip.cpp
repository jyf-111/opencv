#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("D:\\Pictures\\Saved Pictures\\1.jpg");
	Mat dst1,dst2,dst3;
	flip(img, dst1, 1);
	flip(img, dst2, 0);
	flip(img, dst3, -1);
	imshow("img", img);
	imshow("leftright", dst1);
	imshow("updown", dst2);
	imshow("all", dst3);

	waitKey(0);
}