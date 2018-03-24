#ifndef _SMALL_MEAN_LKFLOW_H_
#define _SMALL_MEAN_LKFLOW_H_
#include <opencv2/opencv.hpp>

void smeanlk(cv::Mat& frame, cv::Mat prevFrameGray, cv::Mat currFrameGray, std::vector<cv::Point2f> prevCorners, std::vector<cv::Point2f> currCorners, double& meanflowx, double& meanflowy);

#endif _SMALL_MEAN_LKFLOW_H_