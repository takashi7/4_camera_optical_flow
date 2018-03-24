//#include "video.h"
//#include "display.h"
//#include "lkflow.h"
//#include "timer.h"
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
//
//	while (1) {
//		Timer_test.start_TickMeter();
//
//		//-----------------------------------
//		Lkflow_test.process();
//		Display_test.show(Lkflow_test.get_frame());
//		Lkflow_test.lkloop();
//		//-----------------------------------
//
//		if (cv::waitKey(cycle) == 27) break;
//		Timer_test.end_TickMeter_1frme();
//	}
//
//}