#ifndef _CALC_MOTION_PARAMETERS_H_
#define _CALC_MOTION_PARAMETERS_H_
#include <opencv2/opencv.hpp>

void calc_motion_parameters(cv::Mat Flow, cv::Mat Jacobian, cv::Mat& parameters);

#endif _CALC_MOTION_PARAMETERS_H_