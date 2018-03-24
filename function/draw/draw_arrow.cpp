#include "draw_arrow.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>

#include <iostream>

// ----------------------------------------------------------------------------------------------
// Function of Drowing Arrow
void drawArrow(const cv::Mat& arrow, double x, double y, const cv::Scalar& color, int thickness)
{
	double dx = 3 * x, dy = 3 * y;
	double v;
	double ux, uy;
	double bx, by, lx, ly, rx, ry;
	double w = 15, h = 15;
	std::vector<cv::Point> pt;
	if (dx < 100 || dy < 80) {
		line(arrow, cv::Point(320, 240), cv::Point(cvRound(320 + dx), cvRound(240 + dy)), color, thickness);
		v = sqrt(x * x + y * y);
		ux = x / v;
		uy = y / v;
		bx = 320 + dx;
		by = 240 + dy;
		lx = bx - uy * w - ux * h;
		ly = by + ux * w - uy * h;
		rx = bx + uy * w - ux * h;
		ry = by - ux * w - uy * h;
		pt.push_back(cv::Point(cvRound(bx), cvRound(by)));
		pt.push_back(cv::Point(cvRound(lx), cvRound(ly)));
		pt.push_back(cv::Point(cvRound(rx), cvRound(ry)));
		line(arrow, pt[0], pt[1], color, thickness);
		line(arrow, pt[1], pt[2], color, thickness);
		line(arrow, pt[2], pt[0], color, thickness);
		cv::fillConvexPoly(arrow, pt, color, 8, 0);
	}
}
// ----------------------------------------------------------------------------------------------
