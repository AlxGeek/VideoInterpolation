#include "LinearInterpolator.hpp"

LinearInterpolator::LinearInterpolator(std::vector<cv::Mat> transformationMats, double fps) : Interpolator(transformationMats, fps)
{
}

LinearInterpolator::~LinearInterpolator()
{
}

cv::Mat LinearInterpolator::interpolate(double x)
{	
	int i = (int)ceil(x / fps);
	if (i == 0)
		i++;
	return transformationMats[i - 1] + la::getDifferenceMat(transformationMats[i - 1], transformationMats[i], (size_t)fps) * (x - (i - 1) * 10);
}
