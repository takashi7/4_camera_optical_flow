#ifndef _VIDEO_H__
#define _VIDEO_H__

#include <iostream>
#include <opencv2/opencv.hpp>

const int camera_number = 5;
const int const_widhth = 320;
const int const_height = 240;

class Video {
private:
	int m_width;
	int m_height;
	static int m_count;

protected:
	int m_id;
	cv::VideoCapture m_cap[camera_number];
	cv::Mat m_preframe;
	cv::Mat m_frame;

public:
	Video();
	Video(int width, int height);
	virtual ~Video();
	void count();
	bool capture();
	void size();
	void Default();
	cv::Mat get_frame();
};

#endif _VIDEO_H__