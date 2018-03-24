#ifndef _FILTER_H_
#define _FILTER_H_

#include <opencv2/opencv.hpp>

const int const_avestore = 10;

class Filter {
private:
	std::vector<double> m_storex, m_storey, m_storez;

protected:
	

public:
	Filter();
	double m_vx, m_vy, m_vz;
	double m_wx, m_wy, m_wz;
	double m_avex, m_avey, m_avez;
	void calc_vw(const std::vector<double>, const std::vector<double>);
	void average(const double, const double);
	void average(const double, const double, const double);
};

#endif _FILTER_H_