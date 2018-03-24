#ifndef _DRAW_3D_ARROW_H_
#define _DRAW_3D_ARROW_H_
#include <opencv2/opencv.hpp>

void draw3dArrow(const cv::Mat& arrow, double x, double y, double z, const cv::Scalar& color0, const cv::Scalar& color1, int thickness);

#endif _DRAW_3D_ARROW_H_