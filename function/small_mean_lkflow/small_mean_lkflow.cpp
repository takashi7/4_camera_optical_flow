#include "small_mean_lkflow.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>
#include <numeric>

void smeanlk(cv::Mat& frame, cv::Mat prevFrameGray, cv::Mat currFrameGray, std::vector<cv::Point2f> prevCorners, std::vector<cv::Point2f> currCorners, double& meanflowx, double& meanflowy)
{
	std::vector<double> flowx, flowy;
	
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
