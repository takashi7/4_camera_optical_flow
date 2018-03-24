#include "display.h"

#include <iostream>
#include <opencv2/opencv.hpp>

Display::Display() {
}

Display::Display(const int& id) {
	m_id = id;
	default_window();
}

void Display::default_window() {	
	m_winname = "camera" + std::to_string(m_id);
	cv::namedWindow(m_winname, CV_WINDOW_AUTOSIZE);
	//cv::resizeWindow(m_winname, 640, 480);
	//m_window = (cv::Size(640, 480), CV_8UC3, cv::Scalar(255, 255, 255));
}

void Display::show(const cv::Mat& frame) {
	cv::imshow(m_winname, frame);
}