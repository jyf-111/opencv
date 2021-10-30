#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/dnn.hpp>
using namespace cv;
using namespace std;

int main()
{
	dnn::Net net = cv::dnn::readNetFromTensorflow("opencv_face_detector_uint8.pb", "opencv_face_detector.pbtxt");

	VideoCapture cap(0);
	Mat frame;
	while (1) {
		cap >> frame;
		if (!frame.empty()) {
			Mat blob = cv::dnn::blobFromImage(frame, 1.0, Size(300, 300), Scalar(104, 177, 123), false, false);
			net.setInput(blob);
			Mat probs = net.forward();

			Mat detectionMat(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
			for (int i = 0; i < detectionMat.rows; i++) {
				float confidence = detectionMat.at<float>(i, 2);
				if (confidence > 0.5) {
					int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
					int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
					int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
					int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);
					Rect box(x1, y1, x2 - x1, y2 - y1);
					rectangle(frame, box, Scalar(0, 0, 255), 2, 8, 0);
					cv::putText(frame(box), std::to_string(confidence), Point(10, 10), cv::FONT_HERSHEY_SIMPLEX, 0.45, CV_RGB(255, 230, 0), 1.8);
				}
			}
			imshow("frame", frame);
			// std::vector<Mat> v;
			// split(frame, v);

			// equalizeHist(v[0], v[0]);
			// equalizeHist(v[1], v[1]);
			// equalizeHist(v[2], v[2]);

			// merge(v, frame);

			// imshow("equalizeHist", frame);

			int c = waitKey(10);
			if (c == 27) {
				break;
			}
		}
		else {
			break;
		}
	}
	
	frame.release();
	cap.release();
	waitKey(0);
	return 0;
}