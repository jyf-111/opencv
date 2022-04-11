#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    VideoCapture v("opencv/DCS.flv");
    Mat frame;
    while(1){
        waitKey(25);
            v >> frame;
            std::cout << "read" << std::endl;
            if(!frame.empty())
                imshow("frame", frame);
    }
    frame.release();
    v.release();
    waitKey(0);
    return 0;
}