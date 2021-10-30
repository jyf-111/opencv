#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat m = imread("D:\\Pictures\\Saved Pictures\\DCS.png",CV_8UC4);
	namedWindow("image",WINDOW_FREERATIO);
	imshow("image", m);
	Mat dst = Mat::zeros(m.size(), m.type());
	while (true) {
		int c = waitKey(10);
		if (c == 27)break;
		if (c == 49) {
			cvtColor(m, dst, COLOR_BGR2RGB);
			imshow("image", dst);
		}
		if (c == 50) {
			cvtColor(m, dst, COLOR_BGR2HSV);
			imshow("image", dst);
		}
		if (c == 51) {
			cvtColor(m, dst, COLOR_BGR2GRAY);
			imshow("image", dst);
		}
		if (c == 52) {
			Mat m1 = Mat::zeros(m.size(), m.type());
			m1 = Scalar(50, 50, 50);
			add(m, m1, m1);
			imshow("image", m1);
		}

	}
	
	waitKey(0);
	destroyAllWindows();
}