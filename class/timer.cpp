#include "timer.h"


Timer::Timer() : m_count(0), m_msec_1frame(0), m_msec_10frame(0), m_storetime(0) {
}

void Timer::start_TickMeter() {
	m_meter.reset();
	m_meter.start();
}

void Timer::end_TickMeter_1frme() {
	m_meter.stop();
	m_msec_1frame = m_meter.getTimeMilli();
	std::cout << "Time taken : " << m_msec_1frame << " [ms]" << std::endl;
	std::cout << "Frame Rate : " << 1000 / m_msec_1frame << " [fps]" << std::endl;
}

void Timer::end_TickMeter_10frme() {
	m_meter.stop();
	m_msec_1frame = m_meter.getTimeMilli();
	++m_count;
	if (m_count < 11)
		m_storetime += m_msec_1frame;
	else {
		m_msec_10frame = m_storetime / 10;
		m_storetime = 0;
		m_count = 0;
		std::cout << "Time taken : " << m_msec_10frame << " [ms]" << std::endl;
		std::cout << "Frame Rate : " << 1000 / m_msec_10frame << " [fps]" << std::endl;
	}	
}