#define OPENCV
#define GPU

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <fstream>
#include "yolo_v2_class.hpp"

using namespace std;
using namespace cv;

//画出检测框和相关信息
void DrawBoxes(Mat& frame, vector<string> classes, int classId, float conf, int left, int top, int right, int bottom)
{
	//画检测框
	rectangle(frame, Point(left, top), Point(right, bottom), Scalar(255, 178, 50), 3);
	//该检测框对应的类别和置信度
	string label = format("%.2f", conf);
	if (!classes.empty())
	{
		CV_Assert(classId < (int)classes.size());
		label = classes[classId] + ":" + label;
	}
	//将标签显示在检测框顶部
	int baseLine;
	Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
	top = max(top, labelSize.height);
	rectangle(frame, Point(left, top - round(1.5 * labelSize.height)), Point(left + round(1.5 * labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
	putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 0), 1);
}

//画出检测结果
void Drawer(Mat& frame, vector<bbox_t> outs, vector<string> classes)
{
	//获取所有最佳检测框信息
	for (int i = 0; i < outs.size(); i++)
	{
		DrawBoxes(frame, classes, outs[i].obj_id, outs[i].prob, outs[i].x, outs[i].y,
			outs[i].x + outs[i].w, outs[i].y + outs[i].h);
	}
}

int main()
{
	string classesFile = "C:/Users/jyf/source/repos/opencv/x64/Release/coco.names";
	string modelConfig = "C:/Users/jyf/source/repos/opencv/x64/Release/yolov4.cfg";
	string modelWeights = "C:/Users/jyf/source/repos/opencv/x64/Release/yolov4.weights";

	//加载类别名
	vector<string> classes;
	ifstream ifs(classesFile.c_str());
	string line;
	while (getline(ifs, line)) classes.push_back(line);
	//加载网络模型，0是指定第一块GPU
	Detector detector(modelConfig, modelWeights, 0);
	
	string mode = "video";
	//图像
	if (mode == "image")
	{
		Mat frame = imread("C:/Users/jyf/source/repos/opencv/x64/Release/data/dog.jpg");
		//Mat图像转为yolo输入格式
		if (frame.empty()) {
			std::cout << "empty picture" << endl;
			exit(0);
		}
		
		shared_ptr<image_t> detImg = detector.mat_to_image_resize(frame);
		//前向预测
		vector<bbox_t> outs = detector.detect_resized(*detImg, frame.cols, frame.rows, 0.25);

		//画图
		Drawer(frame, outs, classes);
		imwrite("./data/result.jpg", frame);
		imshow("hihi", frame);
	}
	//视频
	else if (mode == "video"){
		VideoCapture cap("C:/Users/jyf/source/repos/opencv/x64/Release/data/DCS.flv");
		Size size(1920/2, 1080/2);
		if (!cap.isOpened()) {
			cout << "empty" << endl;
			exit(0);
		}
		//VideoWriter writer("./data/result.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 25, size);
		while (1){
			Mat frame;
			cap >> frame;
			resize(frame, frame, size);
			if (frame.empty()) {
				break;
			}
			//Mat图像转为yolo输入格式
			shared_ptr<image_t> detImg = detector.mat_to_image_resize(frame);
			//前向预测
			vector<bbox_t> outs = detector.detect_resized(*detImg, frame.cols, frame.rows, 0.25);
			//画图
			Drawer(frame, outs, classes);
			//writer << frame;
			imshow("hihi", frame);
			if (waitKey(10) == 27) break;
		}
		cap.release();
	}
	cv::waitKey();
	return 0;
}
