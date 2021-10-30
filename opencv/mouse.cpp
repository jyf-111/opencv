#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Point sp(-1, -1);
Point ep(-1, -1);

void my_mousecallback(int event, int x, int y, int flag, void* userdata) {
	Mat m = *((Mat*)userdata);
	if (event == EVENT_LBUTTONDOWN) {
		sp.x = x;
		sp.y = y;

		cout << sp << endl;
	}else if(event==EVENT_LBUTTONUP){
		ep.x = x;
		ep.y = y;
		cout << ep << endl;

		int w = ep.x - sp.x;
		int h = ep.y - sp.y;
		if (w > 0 && h > 0) {
			Rect box(sp.x, sp.y, w, h);
			imshow("ROI", m(box));
			Mat bk;
			m.copyTo(bk);
			rectangle(bk, box, Scalar(0, 0, 255), 2, LINE_8, 0);
			imshow("1", bk);
			
			sp = Point(-1, -1);
			ep = Point(-1, -1);
		}
		
	}
	else if (event == EVENT_MOUSEMOVE) {
		ep.x = x;
		ep.y = y;
		int w = ep.x - sp.x;
		int h = ep.y - sp.y;
		if (w > 0 && h > 0 && sp.x>0 && sp.y >0) {
			Mat bg;
			m.copyTo(bg);
			Rect box(sp.x, sp.y, w, h);
			rectangle(bg, box, Scalar(0, 0, 255), 2, LINE_8, 0);
			imshow("1", bg);
		}
	}
}
int main()
{
	Mat m = imread("D:\\Pictures\\Saved Pictures\\1.jpg");
	namedWindow("1", WINDOW_AUTOSIZE);
	setMouseCallback("1", my_mousecallback, (void*)&m);
	imshow("1",m);
	waitKey(0);
	return 0;
}