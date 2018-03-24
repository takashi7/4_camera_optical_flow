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
//	Lkflow Lkflow_test0, Lkflow_test1, Lkflow_test2, Lkflow_test3;
//	Display Display_test0(0), Display_test1(1), Display_test2(2), Display_test3(3);
//	Timer Timer_test;
//	//Graph Graph_test;
//
//
//	while (1) {
//		Timer_test.start_TickMeter();
//
//		//----------------------------------------------------------------------------------------------------
//		std::thread th0_process(&Lkflow::process, &Lkflow_test0);
//		std::thread th1_process(&Lkflow::process, &Lkflow_test1);
//		std::thread th2_process(&Lkflow::process, &Lkflow_test2);
//		std::thread th3_process(&Lkflow::process, &Lkflow_test3);
//		th0_process.join();
//		th1_process.join();
//		th2_process.join();
//		th3_process.join();
//
//		std::thread th0_loop(&Lkflow::lkloop, &Lkflow_test0);
//		std::thread th1_loop(&Lkflow::lkloop, &Lkflow_test1);
//		std::thread th2_loop(&Lkflow::lkloop, &Lkflow_test2);
//		std::thread th3_loop(&Lkflow::lkloop, &Lkflow_test3);
//		th0_loop.join();
//		th1_loop.join();
//		th2_loop.join();
//		th3_loop.join();
//
//		Display_test0.show(Lkflow_test0.get_frame());
//		Display_test1.show(Lkflow_test1.get_frame());
//		Display_test2.show(Lkflow_test2.get_frame());
//		Display_test3.show(Lkflow_test3.get_frame());
//		//Graph_test.draw_2d_graph(3 * Lkflow_test.m_meanflowx, 3 * Lkflow_test.m_meanflowy);
//		//----------------------------------------------------------------------------------------------------
//
//
//		if (cv::waitKey(cycle) == 27) break;
//		Timer_test.end_TickMeter_1frme();
//	}
//
//}