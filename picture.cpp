#include<opencv2/opencv.hpp>
#include<iostream>
#include<Windows.h>
using namespace std;
using namespace cv;
std::string txt;

void convert(Mat &frame);

unsigned char d[4] = {'@', '|', ' ', ' '};

int main()
{
    VideoCapture cap("1.flv");
    Mat frame;
    while(1){
        cap >> frame;
        resize(frame, frame, Size(frame.cols / 10, frame.rows / 10));
        cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

        convert(frame);

        imshow("img", frame);
        int c = waitKey(1000);
        if(c==27){
            break;
        }

		//将光标移动到（0，0）处
        HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos;
        pos.X = 0;
        pos.Y = 100;
        SetConsoleCursorPosition(hConsoleOutput, pos);

		//输出当前字符
		cout << txt;
    }
    waitKey(0);
}


void convert(Mat &frame){
    txt.clear();
    for (int i = 0; i < frame.rows;i++){
        for (int j = 0; j < frame.cols;j++){
            int val = frame.at<uchar>(i, j);
            if (frame.at<uchar>(i, j)<= 50) {
			 cout << d[0];
			 txt.push_back(d[0]);
		    }
            if (frame.at<uchar>(i, j) > 50 && frame.at<uchar>(i, j) <= 100) {
                cout << d[1];
                txt.push_back(d[1]);
            }
            if (frame.at<uchar>(i, j) > 100 && frame.at<uchar>(i, j) <= 150) {
                cout << d[2];
                txt.push_back(d[2]);
            }
            else {
                cout << d[3];
                txt.push_back(d[3]);
            }
        }
        txt+="\n";
    }
}