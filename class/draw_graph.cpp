#include "draw_graph.h"

#include <opencv2/opencv.hpp>
#include<iostream>

int Graph::m_count = 0;

Graph::Graph() : m_time(0){
	default();
	default_window();
}

void Graph::default() {
	m_id = m_count;
	++m_count;
	m_prex = 240;
	m_prey = 240;
	m_prez = 240;
	m_thickness = const_thickness;
	m_colorx = const_colorx;
	m_colory = const_colory;
	m_colorz = const_colorz;
	cv::Mat graph(cv::Size(640, 480), CV_8UC3, cv::Scalar(255, 255, 255));
	m_graph = graph;
}

void Graph::default_window() {
	m_winname = "graph" + std::to_string(m_id);
	//cv::namedWindow(m_winname, CV_WINDOW_AUTOSIZE);
	cv::namedWindow(m_winname, CV_WINDOW_NORMAL);
	cv::resizeWindow(m_winname, 640, 480);
}

void Graph::set(int thickness, const cv::Scalar& colorx, const cv::Scalar& colory, const cv::Scalar& colorz)
{
	m_thickness = thickness;
	m_colorx = colorx;
	m_colory = colory;
	m_colorz = colorz;
}

// Function of Drowing Graph
void Graph::draw_2d_graph(double x, double y)
{
	m_t = m_time + 50;
	m_x = 240 - x;
	m_y = 240 + y;

	//ä÷êîÇ…Ç∑ÇÈ
	circle(m_graph, cv::Point(50, 240), 5, cv::Scalar(0, 0, 0), 1, 8, 0);
	line(m_graph, cv::Point(50, 450), cv::Point(50, 30), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(10, 240), cv::Point(630, 240), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(50, 30), cv::Point(45, 40), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(50, 30), cv::Point(55, 40), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(630, 240), cv::Point(620, 235), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(630, 240), cv::Point(620, 245), cv::Scalar(0, 0, 0), m_thickness);

	if (m_time < 580) {
		line(m_graph, cv::Point(m_t, m_prex), cv::Point(m_t + 3, m_x), m_colorx, m_thickness);
		line(m_graph, cv::Point(m_t, m_prey), cv::Point(m_t + 3, m_y), m_colory, m_thickness);
		m_time += 3;
	}
	else {
		m_time = 0;
		m_graph = cv::Scalar(255, 255, 255);
	}
	m_prex = m_x;
	m_prey = m_y;
	show(m_graph);
}

void Graph::draw_3d_graph(double x, double y, double z)
{
	m_t = m_time + 50;
	m_x = 240 + x;
	m_y = 240 + y;
	m_z = 240 + z;

	//ä÷êîÇ…Ç∑ÇÈ
	circle(m_graph, cv::Point(50, 240), 5, cv::Scalar(0, 0, 0), 1, 8, 0);
	line(m_graph, cv::Point(50, 450), cv::Point(50, 30), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(10, 240), cv::Point(630, 240), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(50, 30), cv::Point(45, 40), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(50, 30), cv::Point(55, 40), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(630, 240), cv::Point(620, 235), cv::Scalar(0, 0, 0), m_thickness);
	line(m_graph, cv::Point(630, 240), cv::Point(620, 245), cv::Scalar(0, 0, 0), m_thickness);

	if (m_time < 580) {
		line(m_graph, cv::Point(m_t, m_prex), cv::Point(m_t + 3, m_x), m_colorx, m_thickness);
		line(m_graph, cv::Point(m_t, m_prey), cv::Point(m_t + 3, m_y), m_colory, m_thickness);
		line(m_graph, cv::Point(m_t, m_prez), cv::Point(m_t + 3, m_z), m_colorz, m_thickness);
		m_time += 3;
	}
	else {
		m_time = 0;
		m_graph = cv::Scalar(255, 255, 255);
	}
	m_prex = m_x;
	m_prey = m_y;
	m_prez = m_z;
	show(m_graph);
}