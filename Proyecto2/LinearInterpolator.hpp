#pragma once

#include "Interpolator.hpp"
#include "LinearAlgebra.hpp"

class LinearInterpolator :
	public Interpolator
{
private:

public:
	LinearInterpolator(std::vector<cv::Mat> transformationMats, double fps);
	~LinearInterpolator();

	cv::Mat interpolate(double x);

};
