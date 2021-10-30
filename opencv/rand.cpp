#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat bk = Mat::zeros(Size(500, 500), CV_8UC3);
	bk = Scalar(0, 0, 0);
	RNG rng(12345);

	while (1) {
		int c = waitKey(1);
		if (c == 27) break;
		int x1 = rng.uniform(0, bk.cols);
		int y1 = rng.uniform(0, bk.rows);
		int x2 = rng.uniform(0, bk.cols);
		int y2 = rng.uniform(0, bk.rows);
		int r = rng.uniform(0, 255);
		int b = rng.uniform(0, 255);
		int g = rng.uniform(0, 255);
		//bk = Scalar(0, 0, 0);
		line(bk, Point(x1, y1), Point(x2, y2), Scalar(r, b, g), 1, LINE_AA, 0);
		imshow("fiture", bk);
	}
	//waitKey(0);
	destroyAllWindows();
	return 0;
}