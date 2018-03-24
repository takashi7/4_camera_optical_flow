#include "filter.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <numeric>

Filter::Filter() {
	m_storex.assign(const_avestore, 0);
	m_storey.assign(const_avestore, 0);
	m_storez.assign(const_avestore, 0);
	m_vx = 0; m_vy = 0; m_vz = 0;
	m_wx = 0; m_wy = 0; m_wz = 0;
}

void Filter::calc_vw(const std::vector<double> x, const std::vector<double> y) {
	// Calculate the Translational Velocity 'v'
	m_vx = (x[0] - x[2]) / 2;
	m_vy = (y[0] + y[1] + y[2] + y[3]) / 4;
	m_vz = (x[1] - x[3]) / 2;

	// Calculate the Angular Velocity 'w'
	m_wx = (y[2] - y[0]) / 2;
	m_wy = (x[0] + x[1] + x[2] + x[3]) / 4;
	m_wz = (y[3] - y[1]) / 2;
}

void Filter::average(const double x, const double y) {
	m_storex.erase(m_storex.begin());
	m_storey.erase(m_storey.begin());
	m_storex.push_back(x);
	m_storey.push_back(y);
	m_avex = accumulate(m_storex.begin(), m_storex.end(), 0.0) / m_storex.size();
	m_avey = accumulate(m_storey.begin(), m_storey.end(), 0.0) / m_storey.size();
}

void Filter::average(const double x, const double y, const double z) {
	m_storex.erase(m_storex.begin());
	m_storey.erase(m_storey.begin());
	m_storez.erase(m_storez.begin());
	m_storex.push_back(x);
	m_storey.push_back(y);
	m_storez.push_back(z);
	m_avex = accumulate(m_storex.begin(), m_storex.end(), 0.0) / m_storex.size();
	m_avey = accumulate(m_storey.begin(), m_storey.end(), 0.0) / m_storey.size();
	m_avez = accumulate(m_storez.begin(), m_storez.end(), 0.0) / m_storez.size();
}