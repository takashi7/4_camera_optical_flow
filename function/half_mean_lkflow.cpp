#include "half_mean_lkflow.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>
#include <numeric>



//Processing time =  [ms]
void half_mean_lkflow(cv::VideoCapture cap, cv::Mat& frame, cv::Mat& prevFrameGray, std::vector<cv::Point2f>& prevCorners, double& meanflowx, double& meanflowy)
{
	//----------------------------
	//Processing time = 0.05 [ms]
	cap >> frame;
	//----------------------------

	//----------------------------
	//Processing time =  [ms]	
	cv::Mat currFrameGray;
	//----------------------------

	//----------------------------------------------------	
	//RGB to Gray
	//Processing time =  [ms]
	cv::cvtColor(frame, currFrameGray, CV_RGB2GRAY);
	//----------------------------------------------------

	//------------------------------------
	//Processing time =  [ms]
	std::vector<cv::Point2f> currCorners;
	std::vector<double> flowx, flowy;
	//------------------------------------
	
	//std::cout << "currCorners : " << currCorners << std::endl;
	//std::cout << "prevCorners : " << prevCorners << std::endl;
	
	//-------------------------------------------------------------------
	//Processing time = 11 [ms]
	cv::goodFeaturesToTrack(currFrameGray, currCorners, 20, 0.05, 5.0);
	//-------------------------------------------------------------------
	
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Processing time =  [ms]
	cv::cornerSubPix(currFrameGray, currCorners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------

	//std::cout << "currCorners : " << currCorners << std::endl;

	//---------------------------------
	//Processing time =  [ms]
	std::vector<uchar> featuresFound;
	std::vector<float> featuresErrors;
	//---------------------------------

	//------------------------------------------------
	//Processing time =  [ms]
	cv::Mat storepre = currFrameGray;
	std::vector<cv::Point2f> storepreco = currCorners;
	//------------------------------------------------

	//------------------------------
	//Processing time =  [ms]
	cv::calcOpticalFlowPyrLK(
		prevFrameGray,
		currFrameGray,
		prevCorners,
		currCorners,
		featuresFound,
		featuresErrors
	);
	//------------------------------

	//std::cout << "currCorners : " << currCorners << std::endl;

	//-----------------------------------------------------------------------------
	//Processing time =  [ms]
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
	//Processing time =  [ms]
	meanflowx = (-1) * accumulate(flowx.begin(), flowx.end(), 0.0) / flowx.size();
	meanflowy = (-1) * accumulate(flowy.begin(), flowy.end(), 0.0) / flowy.size();
	//-----------------------------------------------------------------------------
	
	//どこで初期化するか　→　いらない（全て置き換えるから）
	prevFrameGray = storepre;
	prevCorners = storepreco;
}
