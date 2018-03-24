#include "determin_strong_corners.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

void Corners(cv::Mat FrameGray, std::vector<cv::Point2f>& corners)
{
	cv::goodFeaturesToTrack(FrameGray, corners, 20, 0.05, 5.0);
	cv::cornerSubPix(FrameGray, corners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));
}
