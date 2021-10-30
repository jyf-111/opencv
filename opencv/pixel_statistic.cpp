#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat img = imread("D:\\Pictures\\Saved Pictures\\DCS.png");
	namedWindow("img", WINDOW_FREERATIO);

	double minv=0, maxv=0;
	Point minLoc, maxLoc;
	std::vector<Mat> v;
	split(img, v);
	for (int i = 0; i < v.size(); i++) {
		minMaxLoc(v[i], &minv, &maxv, &minLoc, &maxLoc, Mat());
		cout << "channel #" << i << endl;
		cout << minv << " ";
		cout << maxv << " ";
		cout << minLoc << " ";
		cout << maxLoc << endl;

		Mat mean, stddev;
		meanStdDev(v[i], mean, stddev);
		cout << mean << " " << stddev << endl;
	}
		

	imshow("img",img);
	waitKey(0);
	destroyAllWindows();
	return 0;
}