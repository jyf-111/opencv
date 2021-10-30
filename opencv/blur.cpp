#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat m = imread("D:\\Pictures\\Saved Pictures\\DCS.png");
	resize(m, m, Size(m.cols / 3, m.rows / 3));
	Mat dst;
	imshow("m", m);
	blur(m, dst, Size(15,15), Point(-1, -1));
	imshow("blur", dst);
	GaussianBlur(m, dst, Size(15, 15),5);
	imshow("GaussionBlur", dst);
	bilateralFilter(m, dst, 0, 100, 10);
	imshow("bilateralFilter", dst);
	waitKey(0);

}