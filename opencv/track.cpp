#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;


int lightness = 50;
int contrast = 100;

void tarck_on_1(int b, void* pic) {
	Mat image = *(static_cast<Mat*>(pic));
	Mat src = image;
	Mat dst ;
	Mat m = Mat::zeros(image.size(), image.type());
	addWeighted(src, 1, m, 0.0, b, dst);
	imshow("fiture", dst);
}

void tarck_on_2(int b, void* pic) {
	double c= b / 100.0;
	Mat image = *(static_cast<Mat*>(pic));
	Mat src = image;
	Mat dst;
	Mat m = Mat::zeros(image.size(), image.type());
	addWeighted(src, c, m, 0.0, 0, dst);
	imshow("fiture", dst);
}


void tracking_bar_demo(Mat &image){
	namedWindow("fiture", WINDOW_AUTOSIZE);

	createTrackbar("track1", "fiture", &lightness,100, tarck_on_1,(void*)(&image));
	createTrackbar("track2", "fiture", &contrast, 200, tarck_on_2, (void*)(&image));
}

int main()
{
	Mat m = imread("./1.jpg");
	imshow("fiture1", m);

	tracking_bar_demo(m);

	waitKey(0);
	destroyAllWindows();
	return 0;
}