#pragma once

#define _USE_MATH_DEFINES
#include <cmath> 

#include <vector>
#include <opencv2\opencv.hpp>

namespace la
{
	bool solveTriDiagonal(const double* a, const double* b, const double* c, const double* d, double* x, const size_t n);

	void transformImage(cv::Mat input, cv::Mat &output, cv::Mat transMat);

	cv::Mat getDifferenceMat(cv::Mat m1, cv::Mat m2, size_t n);

	cv::Mat createTransformationMat(double angle, cv::Point2i center, double tx, double ty);

}