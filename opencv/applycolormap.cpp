#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	int colorMap[] = {
		COLORMAP_AUTUMN,
		COLORMAP_BONE,
		COLORMAP_CIVIDIS,
		COLORMAP_COOL,
		COLORMAP_DEEPGREEN,
		COLORMAP_HOT,
		COLORMAP_HSV,
		COLORMAP_INFERNO,
		COLORMAP_JET,
	};
	Mat m = imread("D:\\Pictures\\Saved Pictures\\DCS.png");
	Mat dst = Mat::zeros(m.size(), m.type());
	namedWindow("img", WINDOW_FREERATIO);
	imshow("img", m);
	int index = 0;
	while (1) {
		int c = waitKey(100);
		if (c == 27)break;
		applyColorMap(m, dst, colorMap[index]);
		imshow("img", dst);
		index++;
		index %= 9;
	}
	destroyAllWindows();
}