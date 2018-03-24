#include "draw_3d_graph.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>

#include <iostream>

// ----------------------------------------------------------------------------------------------
// Function of Drowing Graph
void draw3DGraph(const cv::Mat& graph, int time, double prex, double x, double prey, double y, double prez, double z, const cv::Scalar& colorx, const cv::Scalar& colory, const cv::Scalar& colorz, int thickness)
{
	int t = time + 50;
	double preX = 240 + prex, preY = 240 + prey, preZ = 240 + prez;
	double X = 240 + x, Y = 240 + y, Z = 240 + z;
	circle(graph, cv::Point(50, 240), 5, cv::Scalar(0, 0, 0), 1, 8, 0);

	line(graph, cv::Point(50, 450), cv::Point(50, 30), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(10, 240), cv::Point(630, 240), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(50, 30), cv::Point(45, 40), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(50, 30), cv::Point(55, 40), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(630, 240), cv::Point(620, 235), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(630, 240), cv::Point(620, 245), cv::Scalar(0, 0, 0), thickness);

	if (time != -1) {
		line(graph, cv::Point(t, preX), cv::Point(t + 3, X), colorx, thickness);
		line(graph, cv::Point(t, preY), cv::Point(t + 3, Y), colory, thickness);
		line(graph, cv::Point(t, preZ), cv::Point(t + 3, Z), colorz, thickness);
	}
}
// ----------------------------------------------------------------------------------------------