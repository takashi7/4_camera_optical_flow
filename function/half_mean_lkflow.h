#ifndef _HALF_MEAN_LKFLOW_H_
#define _HALF_MEAN_LKFLOW_H_

#include <iostream>
#include <opencv2/opencv.hpp>

void half_mean_lkflow(cv::VideoCapture cap, cv::Mat& frame, cv::Mat& prevFrameGray, std::vector<cv::Point2f>& prevCorners, double& meanflowx, double& meanflowy);

#endif _HALF_MEAN_LKFLOW_H_