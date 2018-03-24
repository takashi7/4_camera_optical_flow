#ifndef _MEAN_LKFLOW_H_
#define _MEAN_LKFLOW_H_
#include <opencv2/opencv.hpp>

void mean_lkflow(cv::VideoCapture cap, cv::Mat& frame, cv::Mat prevFrame, double& meanflowx, double& meanflowy);

#endif _MEAN_LKFLOW_H_

