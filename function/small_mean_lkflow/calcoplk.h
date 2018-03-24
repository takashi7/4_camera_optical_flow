#ifndef _CALCOPLK_H_
#define _CALCOPLK_H_
#include <opencv2/opencv.hpp>

void calcoplk(cv::VideoCapture cap, cv::Mat& frame, cv::Mat prevFrame, std::vector<cv::Point2f>& prevCorners, std::vector<cv::Point2f>& currCorners, std::vector<uchar>& featuresFound);

#endif _CALCOPLK_H_