#include "draw_graph.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>

#include <iostream>

// ----------------------------------------------------------------------------------------------
// Function of Drowing Graph
void drawGraph(const cv::Mat& graph, int time, double preflowx, double flowx, double preflowy, double flowy, const cv::Scalar& color, int thickness)
{
	int t = time + 50;
	double prex = 240 - preflowx, prey = 240 + preflowy;
	double x = 240 - flowx, y = 240 + flowy;
	circle(graph, cv::Point(50, 240), 5, cv::Scalar(0, 0, 0), 1, 8, 0);

	line(graph, cv::Point(50, 450), cv::Point(50, 30), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(10, 240), cv::Point(630, 240), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(50, 30), cv::Point(45, 40), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(50, 30), cv::Point(55, 40), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(630, 240), cv::Point(620, 235), cv::Scalar(0, 0, 0), thickness);
	line(graph, cv::Point(630, 240), cv::Point(620, 245), cv::Scalar(0, 0, 0), thickness);

	if (time != -1) {
		line(graph, cv::Point(t, prex), cv::Point(t + 3, x), cv::Scalar(0, 0, 255), thickness);
		line(graph, cv::Point(t, prey), cv::Point(t + 3, y), cv::Scalar(0, 255, 0), thickness);
	}
}
// ----------------------------------------------------------------------------------------------


// éQçl
/*
if (t < 580) {
t += 3;
}
else {
t = -1;
graph = cv::Scalar(255, 255, 255);
drawGraph(graph, t, preflowx, meanflowx, preflowy, meanflowy, cv::Scalar(0, 255, 0), 2);
t = 0;
}
*/

