#ifndef _TIMER_H_
#define _TIMER_H_

#include <iostream>
#include <opencv2\opencv.hpp>

class Timer {
private:
	int m_count;
	cv::TickMeter m_meter;
	double m_msec_1frame;
	double m_msec_10frame;
	double m_storetime;

public:
	Timer();
	void start_TickMeter();
	void end_TickMeter_1frme();
	void end_TickMeter_10frme();
};

#endif _TIMER_H_