#include "calcoplk.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>

void calcoplk(cv::VideoCapture cap, cv::Mat& frame, cv::Mat prevFrame, std::vector<cv::Point2f>& prevCorners, std::vector<cv::Point2f>& currCorners,	std::vector<uchar>& featuresFound)
{
	cap >> frame;

	cv::Mat prevFrameGray;
	cv::Mat currFrameGray;

	//RGB to Gray
	cv::cvtColor(prevFrame, prevFrameGray, CV_RGB2GRAY);
	cv::cvtColor(frame, currFrameGray, CV_RGB2GRAY);

	cv::goodFeaturesToTrack(prevFrameGray, prevCorners, 20, 0.05, 5.0);
	cv::goodFeaturesToTrack(currFrameGray, currCorners, 20, 0.05, 5.0);
	cv::cornerSubPix(prevFrameGray, prevCorners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));
	cv::cornerSubPix(currFrameGray, currCorners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));

	std::vector<float> featuresErrors;

	cv::calcOpticalFlowPyrLK(
		prevFrameGray,
		currFrameGray,
		prevCorners,
		currCorners,
		featuresFound,
		featuresErrors
	);
}
