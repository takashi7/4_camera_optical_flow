//#include "video.h"
//#include "display.h"
//#include "lkflow.h"
//#include "timer.h"
//#include "draw_graph.h"
//#include "filter.h"
//
//#include <iostream>
//#include <opencv2\opencv.hpp>
//
//const int cycle = 1;
//
//int main(int argc, char** argv)
//{
//	Lkflow Lkflow_test;
//	Display Display_test(0);
//	Timer Timer_test;
//	Graph Graph_test;
//	Filter Filter_test;
//
//	while (1) {
//		Timer_test.start_TickMeter();
//
//		//-------------------------------------------------------------------------
//		Lkflow_test.process();
//		Display_test.show(Lkflow_test.get_frame());
//
//		Filter_test.average(Lkflow_test.m_meanflowx, Lkflow_test.m_meanflowy);
//
//		Graph_test.draw_2d_graph(3 * Filter_test.m_avex, 3 * Filter_test.m_avey);
//		Lkflow_test.lkloop();
//		//-------------------------------------------------------------------------
//
//		if (cv::waitKey(cycle) == 27) break;
//		Timer_test.end_TickMeter_1frme();
//	}
//
//}