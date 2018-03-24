//#include "video.h"
//#include "display.h"
//#include "lkflow.h"
//#include "timer.h"
//#include "draw_graph.h"
//
//#include <iostream>
//#include <opencv2\opencv.hpp>
//#include <thread>
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
//	cv::Mat frame;
//	double meanflowx, meanflowy;
//
//
//	while (1) {
//		Timer_test.start_TickMeter();
//
//		//----------------------------------------------------------------------------------------------------
//		Lkflow_test.process();
//		//Display_test.show(Lkflow_test.get_frame());
//
//		/*frame = Lkflow_test.get_frame();
//		std::thread th0(&Display::show, &Display_test, frame);*/
//
//		meanflowx = Lkflow_test.m_meanflowx;
//		meanflowy = Lkflow_test.m_meanflowy;
//		std::thread th1(&Graph::draw_2d_graph, &Graph_test, 3 * meanflowx, 3 * meanflowy);
//		
//		std::thread th2(&Lkflow::lkloop, &Lkflow_test);
//
//		//th0.join();
//		th1.join();
//		th2.join();
//
//		//Lkflow_test.process();
//		Display_test.show(Lkflow_test.get_frame());
//		Graph_test.draw_2d_graph(3 * Lkflow_test.m_meanflowx, 3 * Lkflow_test.m_meanflowy);
//		Lkflow_test.lkloop();
//		//----------------------------------------------------------------------------------------------------
//
//
//		if (cv::waitKey(cycle) == 27) break;
//		Timer_test.end_TickMeter_1frme();
//	}
//
//}