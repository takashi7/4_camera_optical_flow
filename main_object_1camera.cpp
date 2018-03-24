//#include "video.h"
//#include "display.h"
//#include "lkflow.h"
//#include "timer.h"
//
//#include <iostream>
//#include <opencv2\opencv.hpp>
//#include <fstream>
//#include <thread>
//
//const int cycle = 1;
//
//int main(int argc, char** argv)
//{
//	Lkflow Lkflow_test;
//	Display Display_test(0), Display_test1(1);
//	Timer Timer_test;
//
//
//	//------------------------------------
//	// File
//	std::ofstream record("objectcamera.csv");
//	int ft = 0;
//	//------------------------------------
//
//	while (1) {
//		Timer_test.start_TickMeter();
//
//		//--------------------------------------------------------------------------
//		Lkflow_test.process();
//		Display_test.show(Lkflow_test.get_frame());
//		
//		//--------------------------------------------------------------------------
//		//File
//		record << ft << ",";
//		record << Lkflow_test.m_meanflowx << "," << Lkflow_test.m_meanflowy << ",";
//		//--------------------------------------------------------------------------
//
//		Lkflow_test.non_error_process();	
//		Display_test1.show(Lkflow_test.get_frame());
//
//		//--------------------------------------------------------------------------
//		//File
//		record << Lkflow_test.m_meanflowx << "," << Lkflow_test.m_meanflowy << ",";
//		//--------------------------------------------------------------------------
//
//		Lkflow_test.lkloop();
//		//--------------------------------------------------------------------------
//
//		if (cv::waitKey(cycle) == 27) break;
//		Timer_test.end_TickMeter_1frme();
//
//
//		//----------------------------------
//		// File
//		record << Timer_test.msec();
//		record << std::endl;
//		++ft;
//		//----------------------------------
//	}
//
//}