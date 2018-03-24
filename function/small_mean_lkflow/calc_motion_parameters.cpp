#include "calc_motion_parameters.h"
#include "calc_Jacobian_Flow.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>


void calc_motion_parameters(cv::Mat Flow, cv::Mat Jacobian, cv::Mat& parameters)
{
	cv::Mat transJacobian;
	cv::Mat proJacobian;
	cv::Mat invJacobian;

	transJacobian = Jacobian.t();
	proJacobian = transJacobian * Jacobian;
	invJacobian = proJacobian.inv();
	parameters = invJacobian * transJacobian * Flow;
}
