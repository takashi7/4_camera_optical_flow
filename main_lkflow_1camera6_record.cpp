//#include "video.h"
//#include "display.h"
//#include "lkflow.h"
//#include "timer.h"
//#include "draw_graph.h"
//
//#include <iostream>
//#include <opencv2\opencv.hpp>
//#include <fstream>
//
//const int cycle = 1;
//
//int main(int argc, char** argv)
//{
//	Lkflow Lkflow_test;
//	Display Display_test(0);
//	Timer Timer_test;
//	Graph Graph_test;
//
//	//------------------------------------
//	// File
//	std::ofstream record("flow.csv");
//	int ft = 0;
//	//------------------------------------
//
//	while (1) {
//		Timer_test.start_TickMeter();
//
//		//-----------------------------------
//		Lkflow_test.process();
//		Display_test.show(Lkflow_test.get_frame());
//		Graph_test.draw_2d_graph(3*Lkflow_test.m_meanflowx, 3*Lkflow_test.m_meanflowy);
//		
//		//------------------------------------------------------------------
//		record << ft;
//		for (int i = 0; i < Lkflow_test.m_flowx.size(); i++) {
//			record << "," << Lkflow_test.m_flowx[i];
//		}
//		record << std::endl;
//		++ft;		
//		//------------------------------------------------------------------
//
//		Lkflow_test.lkloop();
//		//-----------------------------------
//
//		if (cv::waitKey(cycle) == 27) break;
//		Timer_test.end_TickMeter_1frme();
//	}
//
//}