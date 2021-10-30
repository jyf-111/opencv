#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
using namespace std;
using namespace cv;

int main()
{
	Mat m1 = imread("D:\\Pictures\\Saved Pictures\\DCS.png", CV_8UC4);
	Mat dst;
	vector<Mat> mv;
	split(m1, mv);
	char c = getchar();
	switch (c) {
	case 49:
		mv[2] = 0;
		mv[1] = 0;
		break;
	case 50:
		mv[2] = 0;
		mv[0] = 0;
		break;
	case 51:
		mv[0] = 0;
		mv[1] = 0;
		break;

	}
	merge(mv, dst);
	imshow("1", dst);
	int form_to[] = { 0,1,1,2,2,0 };
	mixChannels(&m1, 1, &dst, 1, form_to,3);
	imshow("mix", dst);
	waitKey(0);
}