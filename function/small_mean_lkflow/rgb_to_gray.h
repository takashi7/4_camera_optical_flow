#ifndef _RGB_TO_GRAY_H_
#define _RGB_TO_GRAY_H_
#include <opencv2/opencv.hpp>

void RtoG(cv::VideoCapture cap, cv::Mat& frame, cv::Mat prevFrame, cv::Mat& prevFrameGray, cv::Mat& currFrameGray);

#endif _RGB_TO_GRAY_H_