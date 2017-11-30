#pragma once

#include <opencv2\core\core.hpp>
#include "Interpolator.hpp"
#include "LinearAlgebra.hpp"

class SplineInterpolator : 
	public Interpolator
{
private:
	std::vector<std::vector<double>> coefficients;
	
public:
	SplineInterpolator(std::vector<cv::Mat> transformationMats, double fps);
	~SplineInterpolator();

	cv::Mat interpolate(double x);

	void setCoefficients();
};

