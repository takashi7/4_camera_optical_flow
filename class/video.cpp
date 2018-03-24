#include "video.h"

#include <iostream>
#include <opencv2/opencv.hpp>

int Video::m_count = 0;

Video::Video() : m_width(const_widhth), m_height(const_height){
	count();
	Default();
}

Video::Video(int width, int height) : m_width(width), m_height(height) {
	count();
	Default();
}

Video::~Video() {
	std::cout << "Delete: " << "Camera" << m_id << std::endl;
}

void Video::count() {
	m_id = m_count;
	std::cout << "Generate: " << "Camera" << m_id << std::endl;
	++m_count;
}

bool Video::capture() {
	m_cap[m_id] = m_id;
	if (!m_cap[m_id].isOpened())
		return false;
	else
		return true;
}

void Video::size() {
	m_cap[m_id].set(CV_CAP_PROP_FRAME_WIDTH, m_width);
	m_cap[m_id].set(CV_CAP_PROP_FRAME_HEIGHT, m_height);
}

void Video::Default() {
	capture();
	size();
	m_cap[m_id] >> m_preframe;
}

cv::Mat Video::get_frame() {
	return m_frame;
}