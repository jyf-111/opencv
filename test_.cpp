#include <iostream>
//#define  _CRT_SECURE_NO_WARNINGS
//
//#define OPENCV      // 启用opencv
//#define GPU         // 启用GPU
//
//#include "yolo_v2_class.hpp"
#include <opencv2/opencv.hpp>	
//
//void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,
//	int current_det_fps = -1, int current_cap_fps = -1)
//{
//	int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };
//	for (auto &i : result_vec)
//	{
//		cv::Scalar color = obj_id_to_color(i.obj_id);
//		cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);
//		if (obj_names.size() > i.obj_id)
//		{
//			std::string obj_name = obj_names[i.obj_id];
//			if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
//			cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
//			int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
//			cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 30, 0)),
//				cv::Point2f(std::min((int)i.x + max_width, mat_img.cols - 1), std::min((int)i.y, mat_img.rows - 1)),
//				color, CV_FILLED, 8, 0);
//			putText(mat_img, obj_name, cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
//		}
//	}
//}
//
//std::vector<std::string> objects_names_from_file(std::string const filename)
//{
//	std::ifstream file(filename);
//	std::vector<std::string> file_lines;
//	if (!file.is_open()) return file_lines;
//	for (std::string line; getline(file, line);) file_lines.push_back(line);
//	std::cout << "object names loaded \n";
//	return file_lines;
//}

int main()
{
	//std::string  names_file = "E:/darknet-yolov4/data/coco.names";
	//std::string  cfg_file = "E:/darknet-yolov4/build/darknet/x64/cfg/yolov3.cfg";
	//std::string  weights_file = "E:/darknet-yolov4/build/darknet/x64/yolov3.weights";
	//Detector detector(cfg_file, weights_file);//初始化检测器
	//auto obj_names = objects_names_from_file(names_file);//获得分类对象名称

	// 打开默认摄像头
	cv::VideoCapture capture("E:\\vscode\\opencv\\DCS001.flv");
	//if (!capture.isOpened())
	//{
	//	printf("摄像头打开失败");
	//	return -1;
	//}

	// 实时检测
	cv::Mat frame;
	while (true)
	{
		cv::waitKey(25);
		capture >> frame;
		//std::vector<bbox_t> result_vec = detector.detect(frame);
		//draw_boxes(frame, result_vec, obj_names);
		if(!frame.empty())
			cv::imshow("YOLO v3 Camera", frame);
		//if (cv::waitKey(25) == 27) break;  // ESC键退出
	}
	frame.release();
	capture.release();
	cv::waitKey(0);
	return 0;
}
