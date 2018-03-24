#include "mean_lkflow.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>
#include <numeric>

#include <thread>

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//void RtoG(cv::Mat prevFrame, cv::Mat& prevFrameGray) {
//	cv::cvtColor(prevFrame, prevFrameGray, CV_RGB2GRAY);
//}
//void Feature(cv::Mat FrameGray, std::vector<cv::Point2f>& Corners) {
//	cv::goodFeaturesToTrack(FrameGray, Corners, 20, 0.05, 5.0);
//}
//void Corner(cv::Mat FrameGray, std::vector<cv::Point2f>& Corners) {
//	cv::cornerSubPix(FrameGray, Corners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));
//}
//---------------------------------------------------------------------------------------------------------------------------------------------------------

//Processing time = 32 [ms]
void mean_lkflow(cv::VideoCapture cap, cv::Mat& frame, cv::Mat prevFrame, double& meanflowx, double& meanflowy)
{
	//----------------------------
	//Processing time = 0.05 [ms]
	cap >> frame;
	//----------------------------

	//----------------------------
	//Processing time = 0.0003 [ms]
	cv::Mat prevFrameGray;
	cv::Mat currFrameGray;
	//----------------------------

	//----------------------------------------------------	
	//RGB to Gray
	//Processing time = 0.7 [ms]
	cv::cvtColor(prevFrame, prevFrameGray, CV_RGB2GRAY);
	cv::cvtColor(frame, currFrameGray, CV_RGB2GRAY);
	//----------------------------------------------------
	
	//------------------------------------------------------------
	//std::thread thg0(RtoG, prevFrame, std::ref(prevFrameGray));
	//std::thread thg1(RtoG, frame, std::ref(currFrameGray));
	//thg0.join();
	//thg1.join();
	//------------------------------------------------------------
	
	//------------------------------------
	//Processing time = 0.007 [ms]
	std::vector<cv::Point2f> prevCorners;
	std::vector<cv::Point2f> currCorners;
	std::vector<double> flowx, flowy;
	//------------------------------------

	//-------------------------------------------------------------------
	//Processing time = 20 [ms]
	cv::goodFeaturesToTrack(prevFrameGray, prevCorners, 20, 0.05, 5.0);
	cv::goodFeaturesToTrack(currFrameGray, currCorners, 20, 0.05, 5.0);
	//-------------------------------------------------------------------
		
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Processing time = 3.2 [ms]
	cv::cornerSubPix(prevFrameGray, prevCorners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));
	cv::cornerSubPix(currFrameGray, currCorners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	////-----------------------------------------------------------------
	//std::thread thf0(Feature, prevFrameGray, std::ref(prevCorners));
	//std::thread thf1(Feature, currFrameGray, std::ref(currCorners));
	//thf0.join();
	//thf1.join();
	//std::thread thc0(Corner, prevFrameGray, std::ref(prevCorners));
	//std::thread thc1(Corner, currFrameGray, std::ref(currCorners));
	//thc0.join();
	//thc1.join();
	////-----------------------------------------------------------------
	//

	//---------------------------------
	//Processing time = 0.0065 [ms]
	std::vector<uchar> featuresFound;
	std::vector<float> featuresErrors;
	//---------------------------------
	
	//------------------------------
	//Processing time = 6.2 [ms]
	cv::calcOpticalFlowPyrLK(
		prevFrameGray,
		currFrameGray,
		prevCorners,
		currCorners,
		featuresFound,
		featuresErrors
	);
	//------------------------------
	
	//-----------------------------------------------------------------------------
	//Processing time = 0.27 [ms]
	int j = 0;
	for (int i = 0; i < (int)prevCorners.size(); i++) {
		if (!featuresFound[i])
			continue;
		flowx.push_back(currCorners[i].x - prevCorners[i].x);
		flowy.push_back(currCorners[i].y - prevCorners[i].y);
		cv::line(frame, prevCorners[i], currCorners[i], cv::Scalar(0, 0, 255), 2);
		j++;
	}
	//-----------------------------------------------------------------------------
	
	//-----------------------------------------------------------------------------
	//Processing time = 0.018 [ms]
	meanflowx = (-1) * accumulate(flowx.begin(), flowx.end(), 0.0) / flowx.size();
	meanflowy = (-1) * accumulate(flowy.begin(), flowy.end(), 0.0) / flowy.size();
	//-----------------------------------------------------------------------------


}
