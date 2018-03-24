#include "rgb_to_gray.h"
#include <opencv2/opencv.hpp>

void RtoG(cv::VideoCapture cap, cv::Mat& frame, cv::Mat prevFrame, cv::Mat& prevFrameGray, cv::Mat& currFrameGray)
{	
	cap >> frame;

	cv::cvtColor(prevFrame, prevFrameGray, CV_RGB2GRAY);
	cv::cvtColor(frame, currFrameGray, CV_RGB2GRAY);
}