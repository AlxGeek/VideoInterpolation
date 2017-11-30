#pragma once

#include <opencv2\opencv.hpp>

class Interpolator
{
protected:
	std::vector<cv::Mat> transformationMats;
	double fps;
public:
	Interpolator(std::vector<cv::Mat> transformationMats, double fps);
	~Interpolator();

	virtual cv::Mat interpolate(double x) = 0;

	double getFps();
};

