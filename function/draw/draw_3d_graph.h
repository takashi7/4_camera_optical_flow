#ifndef _DRAW_3D_GRAPH_H_
#define _DRAW_3D_GRAPH_H_
#include <opencv2/opencv.hpp>

void draw3DGraph(const cv::Mat& graph, int time, double prex, double x, double prey, double y, double prez, double z, const cv::Scalar& colorx, const cv::Scalar& colory, const cv::Scalar& colorz, int thickness);

#endif _DRAW_3D_GRAPH_H_