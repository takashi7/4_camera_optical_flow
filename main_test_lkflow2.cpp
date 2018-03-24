//#include "mean_lkflow.h"
//#include "draw_graph.h"
//include "isnan.h"
//#include "average.h"
//#include "weighted_verage.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <fstream>

const int numave = 3;

int main(int argc, char** argv)
{
	cv::VideoCapture cap(0);
	if (!cap.isOpened())
		return -1;
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

	const int cycle = 1;

	cv::Mat graph(cv::Size(640, 480), CV_8UC3, cv::Scalar(255, 255, 255));
	cv::namedWindow("graph", CV_WINDOW_AUTOSIZE);
	cv::Mat avegraph(cv::Size(640, 480), CV_8UC3, cv::Scalar(255, 255, 255));
	cv::namedWindow("avegraph", CV_WINDOW_AUTOSIZE);

	cv::Mat prevFrame;
	cv::Size frameSize = prevFrame.size();
	cap >> prevFrame;

	cv::waitKey(cycle);

	int t1 = 0, t2 = 0;
	double preflowx = 0, preflowy = 0;

	//--------------------------------------------------------
	std::vector<double> storflowx0(5, 0), storflowy0(5, 0);
	std::vector<double> storflowx1(10, 0), storflowy1(10, 0);
	std::vector<double> storflowx2(20, 0), storflowy2(20, 0);
	double aveflowx[numave] = {}, aveflowy[numave] = {};
	double preaveflowx[numave] = {}, preaveflowy[numave] = {};
	//--------------------------------------------------------

	//------------------------------------
	// File
	std::ofstream record("aveflow.csv");
	int ft = 0;
	//------------------------------------

	while (1) {
		cv::Mat frame;

		double meanflowx, meanflowy;
		cap >> frame;

		cv::Mat prevFrameGray;
		cv::Mat currFrameGray;

		//RGB to Gray
		cv::cvtColor(prevFrame, prevFrameGray, CV_RGB2GRAY);
		cv::cvtColor(frame, currFrameGray, CV_RGB2GRAY);

		std::vector<cv::Point2f> prevCorners;
		std::vector<cv::Point2f> currCorners;
		std::vector<double> flowx, flowy;

		cv::goodFeaturesToTrack(prevFrameGray, prevCorners, 20, 0.05, 5.0);
		cv::cornerSubPix(prevFrameGray, prevCorners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));

		std::vector<uchar> featuresFound;
		std::vector<float> featuresErrors;

		cv::calcOpticalFlowPyrLK(
			prevFrameGray,
			currFrameGray,
			prevCorners,
			currCorners,
			featuresFound,
			featuresErrors
		);

		int j = 0;
		for (int i = 0; i < (int)prevCorners.size(); i++) {
			//if (!featuresFound[i])
			if (!featuresFound[i] || featuresErrors[i] > 20)
				continue;
			flowx.push_back(currCorners[i].x - prevCorners[i].x);
			flowy.push_back(currCorners[i].y - prevCorners[i].y);
			cv::line(frame, prevCorners[i], currCorners[i], cv::Scalar(0, 0, 255), 2);
			j++;
			std::cout << "featuresErrors[i] = " << featuresErrors[i] << std::endl;
		}

		meanflowx = (-1) * accumulate(flowx.begin(), flowx.end(), 0.0) / flowx.size();
		meanflowy = (-1) * accumulate(flowy.begin(), flowy.end(), 0.0) / flowy.size();

		//-----------------------------------------------------------
		//IsNaN
		//isnan(meanflowx, meanflowy, preflowx, preflowy);
		//-----------------------------------------------------------

		//-------------------------------------------------------------------------------
		// Average
		//average(meanflowx, meanflowy, storflowx0, storflowy0, aveflowx[0], aveflowy[0]);
		//average(meanflowx, meanflowy, storflowx1, storflowy1, aveflowx[1], aveflowy[1]);
		//average(meanflowx, meanflowy, storflowx2, storflowy2, aveflowx[2], aveflowy[2]);
		//-------------------------------------------------------------------------------

		//----------------------------------------------------------------------------------------
		// Weighted Average
		//weighted_average(meanflowx, meanflowy, storflowx0, storflowy0, aveflowx[0], aveflowy[0]);
		//weighted_average(meanflowx, meanflowy, storflowx1, storflowy1, aveflowx[1], aveflowy[1]);
		//weighted_average(meanflowx, meanflowy, storflowx2, storflowy2, aveflowx[2], aveflowy[2]);
		//----------------------------------------------------------------------------------------

		//--------------------------------------------------------
		// Threshold
		//if (aveflowx[0] < 5 && aveflowx[0]>0) aveflowx[0] = 0;
		//if (aveflowx[0] > -5 && aveflowx[0]<0) aveflowx[0] = 0;
		//if (aveflowy[0] < 5 && aveflowy[0]>0) aveflowy[0] = 0;
		//if (aveflowy[0] > -5 && aveflowy[0]<0) aveflowy[0] = 0;
		//--------------------------------------------------------

		//------------------------------------------------------------------
		record << ft << "," << meanflowx << "," << meanflowy << "," << aveflowx[0] << "," << aveflowy[0] << "," << aveflowx[1] << "," << aveflowy[1] << "," << aveflowx[2] << "," << aveflowy[2] << std::endl;
		++ft;
		//------------------------------------------------------------------

		//std::cout << "(x y) = " << "(" << meanflowx << "	" << meanflowy << ")" << std::endl;
		std::cout << "(x y) = " << "(" << aveflowx[0] << "	" << aveflowy[0] << ")" << std::endl;


		//drawGraph(graph, t1, preflowx, meanflowx, preflowy, meanflowy, cv::Scalar(0, 255, 0), cv::Scalar(0, 0, 255), 2);
		//(avegraph, t2, preaveflowx[1], aveflowx[1], preaveflowy[1], aveflowy[1], cv::Scalar(0, 255, 0), cv::Scalar(0, 0, 255), 2);

		//cv::imshow("graph", graph);
		//cv::imshow("avegraph", avegraph);
		cv::imshow("preview", frame);
		prevFrame = frame;
		if (cv::waitKey(cycle) == 27) break;
	}
	return 0;
}