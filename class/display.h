#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

class Display {
private:
	int m_cycle;
	int m_id;
	cv::Mat m_preframe;
	cv::Mat m_frame;

protected:
	std::string m_winname;
	//cv::Mat m_window;

public:
	Display();
	Display(const int&);
	void default_window();
	void show(const cv::Mat& frame);
};

#endif _DISPLAY_H_