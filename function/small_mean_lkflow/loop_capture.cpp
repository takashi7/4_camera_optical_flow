#include "loop_capture.h"
#include <opencv2/opencv.hpp>

void capture(cv::VideoCapture cap, cv::Mat& frame) {
	cap >> frame;	
}