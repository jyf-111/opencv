#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("D:\\Pictures\\Saved Pictures\\DCS.png");
	namedWindow("img", WINDOW_FREERATIO);

	Rect r;
	r.x = 1000;
	r.y = 500;
	r.width = 500;
	r.height = 500;
	rectangle(img, r, Scalar(0, 255, 255), 2, LINE_8, 0);
	circle(img, Point(1300, 500),100,Scalar(255,0 , 255),4 , 8, 0);

	Mat back = Mat::zeros(img.size(),img.type());	
	back = Scalar(255, 255, 0);
	addWeighted(img, 0.7, back, 0.3, 0, img);

	line(img, Point(0, 0), Point(1000, 1000), Scalar(0, 0, 255), 3, LINE_AA, 0);

	RotatedRect rtt;
	rtt.center = Point(1000, 1000);
	rtt.size = Size(200, 100);
	rtt.angle = 90;
	ellipse(img, rtt, Scalar(255, 255, 255), 3, 8);

	imshow("img", img);
	waitKey(0);
	return 0;
}
