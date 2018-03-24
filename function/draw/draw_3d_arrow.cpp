#include "draw_3d_arrow.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>

#include <iostream>

// ----------------------------------------------------------------------------------------------
// Function of Drowing Arrow
void draw3dArrow(const cv::Mat& arrow, double x, double y, double z, const cv::Scalar& color0, const cv::Scalar& color1, int thickness)
{
	double dx = 3 * x, dy = 3 * y, dz = 3 * z;
	double v;
	double ux, uy;
	double bx, by, lx, ly, rx, ry;
	double w = 15, h = 15;
	std::vector<cv::Point> pt, pt1;
	if (dx < 100 || dy < 80) {
		//---------------------------------------------------------------------------------------------------
		// x and y
		line(arrow, cv::Point(250, 240), cv::Point(cvRound(250 + dx), cvRound(240 + dy)), color0, thickness);
		v = sqrt(x * x + y * y);
		ux = x / v;
		uy = y / v;
		bx = 250 + dx;
		by = 240 + dy;
		lx = bx - uy * w - ux * h;
		ly = by + ux * w - uy * h;
		rx = bx + uy * w - ux * h;
		ry = by - ux * w - uy * h;
		pt.push_back(cv::Point(cvRound(bx), cvRound(by)));
		pt.push_back(cv::Point(cvRound(lx), cvRound(ly)));
		pt.push_back(cv::Point(cvRound(rx), cvRound(ry)));
		line(arrow, pt[0], pt[1], color0, thickness);
		line(arrow, pt[1], pt[2], color0, thickness);
		line(arrow, pt[2], pt[0], color0, thickness);
		cv::fillConvexPoly(arrow, pt, color0, 8, 0);
		//---------------------------------------------------------------------------------------------------

		//---------------------------------------------------------------------------------------------------
		// z
		line(arrow, cv::Point(500, 240), cv::Point(500, 240 + dz), color1, thickness);
		bx = 500;
		by = 240 + dz;
		lx = 500 - w;
		rx = 500 + w;
		if (dz >= 0) {
			ly = by - h;
			ry = by - h;
		}
		else {
			ly = by + h;
			ry = by + h;
		}
		pt1.push_back(cv::Point(cvRound(bx), cvRound(by)));
		pt1.push_back(cv::Point(cvRound(lx), cvRound(ly)));
		pt1.push_back(cv::Point(cvRound(rx), cvRound(ry)));
		line(arrow, pt1[0], pt1[1], color1, thickness);
		line(arrow, pt1[1], pt1[2], color1, thickness);
		line(arrow, pt1[2], pt1[0], color1, thickness);
		cv::fillConvexPoly(arrow, pt1, color1, 8, 0);
		//---------------------------------------------------------------------------------------------------
	}
}
// ----------------------------------------------------------------------------------------------
