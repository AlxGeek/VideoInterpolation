#include "Interpolator.hpp"


Interpolator::Interpolator(std::vector<cv::Mat> transformationMats, double fps) : transformationMats(transformationMats), fps(fps)
{
}

Interpolator::~Interpolator()
{
}

double Interpolator::getFps()
{
	return fps;
}
