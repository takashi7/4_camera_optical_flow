#include "calc_Jacobian_Flow.h"
#include "calcoplk.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>


void calc_Jacobian_Flow(cv::VideoCapture cap, cv::Mat& frame, cv::Mat prevFrame, cv::Mat& Flow, cv::Mat& Jacobian, cv::Mat& parameters, int sign)
{
	std::vector<cv::Point2f> prevCorners;
	std::vector<cv::Point2f> currCorners;
	std::vector<uchar> featuresFound;

	calcoplk(cap, frame, prevFrame, prevCorners, currCorners, featuresFound);

	std::vector<double> flowx, flowy;
	
	double z = 1;

	//--------------------------------------------------------------------------------------------------------------------------------
	//Loop
	int j = 0;
	for (int i = 0; i < (int)prevCorners.size(); i++) {
		if (!featuresFound[i])
			continue;
		flowx.push_back(currCorners[i].x - prevCorners[i].x);
		flowy.push_back(currCorners[i].y - prevCorners[i].y);
		cv::line(frame, prevCorners[i], currCorners[i], cv::Scalar(0, 0, 255), 2);

		//-------------------------------------------------------------------------------------
		//ここでvector subscript out of rangeが出ていた
		//flowx,flowyには常に値が入るわけではないので、flowx[i]に値が入ってない可能性があるため
		cv::Mat flow = (cv::Mat_ <double>(2, 1) << flowx[j], flowy[j]);
		Flow.push_back(flow);
		j++;
		//-------------------------------------------------------------------------------------

		double X = currCorners[i].x;
		double Y = currCorners[i].y;
		cv::Mat Jac = (cv::Mat_<double>(2, 6) << sign * 1 / z, 0, -sign * X / z, sign * X * Y, -1 - X * X, sign * Y, 0, 1 / z, -sign * Y / z, sign * (1 + Y * Y), (-1)*X*Y, (-1)*X);
		Jacobian.push_back(Jac);
	}
	//--------------------------------------------------------------------------------------------------------------------------------
		
}
