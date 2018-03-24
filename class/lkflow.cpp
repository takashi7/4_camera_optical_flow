#include "lkflow.h"

#include <numeric>

// Constructor
Lkflow::Lkflow() : m_meanflowx(0), m_meanflowy(0), m_premeanflowx(0), m_premeanflowy(0){
	//m_cap[m_id] >> m_preframe;
	RGBtoGRAY(m_preframe, m_preFrameGray);
	Features_Detection(m_preFrameGray, m_preCorners);
}

// Convert to Grayscale
void Lkflow::RGBtoGRAY(const cv::Mat& rgb, cv::Mat& gray) {
	cv::cvtColor(rgb, gray, CV_RGB2GRAY);
}

// Feature point extraction
void Lkflow::Features_Detection(const cv::Mat& gray, std::vector<cv::Point2f>& corners) {
	cv::goodFeaturesToTrack(gray, corners, 20, 0.05, 5.0);
	cv::cornerSubPix(gray, corners, cv::Size(10, 10), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 30, 0.01));
}

// Calculate Optical Flow
void Lkflow::lkflow() {
	m_cap[m_id] >> m_frame;
	RGBtoGRAY(m_frame, m_currFrameGray); 
	cv::calcOpticalFlowPyrLK( 
		m_preFrameGray,
		m_currFrameGray,
		m_preCorners,
		m_currCorners,
		m_featuresFound,
		m_featuresErrors
	);
}

// Calculate Mean of Optical Flow
void Lkflow::meanlkflow() {
	for (int i = 0; i < (int)m_preCorners.size(); i++) {
		if (!m_featuresFound[i] || m_featuresErrors[i] > 20)
			continue;
		m_flowx.push_back(m_currCorners[i].x - m_preCorners[i].x);
		m_flowy.push_back(m_currCorners[i].y - m_preCorners[i].y);
		cv::line(m_frame, m_preCorners[i], m_currCorners[i], cv::Scalar(0, 0, 255), 2);
		//std::cout << "featuresErrors[i] = " << m_featuresErrors[i] << std::endl;
	}
	m_meanflowx = (-1) * accumulate(m_flowx.begin(), m_flowx.end(), 0.0) / m_flowx.size();
	m_meanflowy = (-1) * accumulate(m_flowy.begin(), m_flowy.end(), 0.0) / m_flowy.size();
	//std::cout << "(meanx, meany) = " << "( " << m_meanflowx << ", " << m_meanflowy << ")" <<  std::endl;
}

// Exception handling
void Lkflow::isnan() {
	if (std::isnan(m_meanflowx) || std::isnan(m_meanflowy)) {
		m_meanflowx = m_premeanflowx;
		m_meanflowy = m_premeanflowy;
	}
}

void Lkflow::process() {
	lkflow();
	meanlkflow();
	isnan();
}

// For loop
void Lkflow::lkloop() {
	Features_Detection(m_currFrameGray, m_currCorners);
	m_currFrameGray.copyTo(m_preFrameGray);
	m_preCorners = m_currCorners;
	m_flowx.erase(m_flowx.begin(), m_flowx.end());
	m_flowy.erase(m_flowy.begin(), m_flowy.end());
	m_premeanflowx = m_meanflowx;
	m_premeanflowy = m_meanflowy;
}