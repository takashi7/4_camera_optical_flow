#ifndef _CALC_JACOBIAN_FLOW_H_
#define _CALC_JACOBIAN_FLOW_H_
#include <opencv2/opencv.hpp>

void calc_Jacobian_Flow(cv::VideoCapture cap, cv::Mat& frame, cv::Mat prevFrame, cv::Mat& Flow, cv::Mat& Jacobian, cv::Mat& parameters, int sign);

#endif _CALC_JACOBIAN_FLOW_H_