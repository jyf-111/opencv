#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("D:\\Pictures\\Saved Pictures\\DCS.png");
	imshow("1", image);
	Mat hsv, hs_hist;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	int hbins = 30;
	int sbins = 32;
	int hist_bins[] = { hbins,sbins };
	float h_range[] = { 0,180 };
	float s_range[] = { 0,256 };
	const float* hs_range[] = { h_range,s_range };
	int hs_channels[] = { 0,1 };
	calcHist(&hsv, 1, hs_channels, Mat(), hs_hist, 2, hist_bins, hs_range, true, false);

	double maxVal = 0;
	minMaxLoc(hs_hist, 0, &maxVal, 0, 0);
	int scale = 10;
	Mat hist2d_image = Mat::zeros(sbins * scale, hbins * scale, CV_8UC3);
	for (int h = 0; h < hbins; h++) {
		for (int s = 0; s < sbins; s++) {
			float binVal = hs_hist.at<float>(h, s);
			int intensity = cvRound(binVal * 255 / maxVal);
			rectangle(hist2d_image, Point(h * scale, s * scale), Point((h+1) * scale, (s+1) * scale),Scalar::all(intensity),-1);
		}
	}
	applyColorMap(hist2d_image, hist2d_image, COLORMAP_JET);
	imshow("2", hist2d_image);
	waitKey(0);
}