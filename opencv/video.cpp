#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture("DCS.flv"); 
	int num = 100;
	int frame_width = capture.get(CAP_PROP_FRAME_WIDTH);
	int frame_hight = capture.get(CAP_PROP_FRAME_HEIGHT);
	int count = capture.get(CAP_PROP_FRAME_COUNT);
	double fps = capture.get(CAP_PROP_FPS);
	cout << "width = " << frame_width << endl;
	cout << "height = " << frame_hight << endl;
	cout << "count = " << count << endl;
	cout << "fps = " << fps << endl;

	// VideoWriter writer("..\\1.mp4", CAP_PROP_FOURCC, 25.0, Size(frame_width, frame_hight), true);
	Mat frame;

	while (num >0) {
		capture.read(frame);
		if (frame.empty()) {
			break;
		}

		//flip(frame, frame, 1);
		imshow("frame",frame);
		//TODO....

		int c = waitKey(25);
		if (c == 27) {
			break;
		}
		num--;
		// writer.write(frame);
		cout << num << endl;
	}
	destroyAllWindows();
	capture.release();
	// writer.release();
	waitKey(0);
	return 0;
}