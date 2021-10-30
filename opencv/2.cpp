#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

void f(Mat& picture) {
	Mat gray, hsv;
	cvtColor(picture, hsv, COLOR_BGR2HSV);
	cvtColor(picture, gray, COLOR_BGR2GRAY);
	imshow("hsv", hsv);
	imshow("gray", gray);

}

int main()
{
	namedWindow("input", WINDOW_FREERATIO);

	Mat m1 = Mat::ones(Size(500, 500), CV_8UC1);
	m1 = imread("1.jpg");
	m1 = Scalar(255);
	for (int i = 0; i < m1.rows; i++)
	{
		for (int j = 0; j < m1.cols; j++)
		{
			uchar* p = m1.ptr<uchar>(i);
			if (m1.channels() == 1) {
				uchar pv = *p;
				*p++ = 255 - pv;
			}
			if (m1.channels() == 3) {
				Vec3b bgr = m1.at<Vec3b>(i, j);
				m1.at<Vec3b>(i, j)[0]= 255 - bgr[0];
				m1.at<Vec3b>(i, j)[1] = 255 - bgr[1];
				m1.at<Vec3b>(i, j)[2] = 255 - bgr[2];
			}
		}
	}
	imshow("pic", m1);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
