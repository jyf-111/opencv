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
	Mat src = imread("1.jpg");
	
	namedWindow("input", WINDOW_FREERATIO);
	std::cout << src.depth();
	if (src.empty()) {
		std::cout << "is empty" << std::endl;
		return -1;
	}
	f(src);
	imshow("imput", src);
	Mat m = Mat::ones(Size(8, 12), CV_8UC3);
	m = Scalar(255,0,255);
	std::cout << m << std::endl;
	std::cout << m.cols << std::endl;
	std::cout << m.rows << std::endl;
	std::cout << m.channels() << std::endl;


	Mat m1 = Mat::ones(Size(8, 8), CV_8UC3);
	//m1 = m.clone();
	m.copyTo(m1);
	m1 = Scalar(0, 255, 255);

	Mat m2 = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

	namedWindow("picture", WINDOW_FREERATIO);
	namedWindow("picture1", WINDOW_FREERATIO);
	namedWindow("picture2", WINDOW_FREERATIO);
	imshow("picture", m);
	imshow("picture1", m1);
	imshow("picture2", m1);


	// Mat m1 = Mat::ones(Size(500, 500), CV_8UC1);
	// m1 = imread("1.jpg");
	// m1 = Scalar(255);
	// for (int i = 0; i < m1.rows; i++)
	// {
	// 	for (int j = 0; j < m1.cols; j++)
	// 	{
	// 		uchar* p = m1.ptr<uchar>(i);
	// 		if (m1.channels() == 1) {
	// 			uchar pv = *p;
	// 			*p++ = 255 - pv;
	// 		}
	// 		if (m1.channels() == 3) {
	// 			Vec3b bgr = m1.at<Vec3b>(i, j);
	// 			m1.at<Vec3b>(i, j)[0]= 255 - bgr[0];
	// 			m1.at<Vec3b>(i, j)[1] = 255 - bgr[1];
	// 			m1.at<Vec3b>(i, j)[2] = 255 - bgr[2];
	// 		}
	// 	}
	// }
	imshow("pic", m1);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

