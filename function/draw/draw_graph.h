#ifndef _DRAW_GRAPH_H_
#define _DRAW_GRAPH_H_
#include <opencv2/opencv.hpp>

void drawGraph(const cv::Mat& graph, int time, double preflowx, double flowx, double preflowy, double flowy, const cv::Scalar& color, int thickness);

#endif _DRAW_GRAPH_H_