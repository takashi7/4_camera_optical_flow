#ifndef _LKFLOW_H_
#define _LKFLOW_H_

#include "video.h"
#include <iostream>
#include <opencv2/opencv.hpp>

class Lkflow :public Video {
protected:
	cv::Mat m_preFrameGray;
	cv::Mat m_currFrameGray;
	std::vector<cv::Point2f> m_preCorners;
	std::vector<cv::Point2f> m_currCorners;
	//std::vector<double> m_flowx, m_flowy;
	std::vector<uchar> m_featuresFound;
	std::vector<float> m_featuresErrors;

public:
	Lkflow();
	double m_meanflowx, m_meanflowy;
	double m_premeanflowx, m_premeanflowy;
	void RGBtoGRAY(const cv::Mat&, cv::Mat&);
	void Features_Detection(const cv::Mat&, std::vector<cv::Point2f>&);
	void lkflow();
	void meanlkflow();
	void isnan();
	void process();
	void lkloop();
	std::vector<double> m_flowx, m_flowy;
};

#endif _LKFLOW_H_