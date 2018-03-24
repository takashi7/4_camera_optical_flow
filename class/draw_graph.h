#ifndef _DRAW_GRAPH_H_
#define _DRAW_GRAPH_H_

#include "display.h"
#include <opencv2/opencv.hpp>

const int const_thickness = 2;
const cv::Scalar const_colorx = cv::Scalar(0, 0, 255);
const cv::Scalar const_colory = cv::Scalar(0, 255, 0);
const cv::Scalar const_colorz = cv::Scalar(255, 0, 0);

class Graph: public Display{
private:
	static int m_count;
	int m_id;
	int m_time;
	int m_t;
	double m_prex, m_prey, m_prez;
	double m_x, m_y, m_z;
	int m_thickness;
	cv::Scalar m_colorx;
	cv::Scalar m_colory;
	cv::Scalar m_colorz;

protected:
	cv::Mat m_graph;

public:
	Graph();
	void default();
	void default_window();
	void set(int, const cv::Scalar&, const cv::Scalar&, const cv::Scalar&);
	void draw_2d_graph(double, double);
	void draw_3d_graph(double, double, double);
};

#endif _DRAW_GRAPH_H_