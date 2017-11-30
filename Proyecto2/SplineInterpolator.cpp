#include "SplineInterpolator.hpp"

SplineInterpolator::SplineInterpolator(std::vector<cv::Mat> transformationMats, double fps) : 
	Interpolator(transformationMats, fps), coefficients(6)
{
	for (auto &m : coefficients)
		m.resize(transformationMats.size());
	setCoefficients();
}

SplineInterpolator::~SplineInterpolator()
{
}

void SplineInterpolator::setCoefficients()
{
	std::vector<double> ab(transformationMats.size());
	std::vector<double> m(transformationMats.size());
	std::vector<double> b(transformationMats.size(), 2);
	std::vector<double> l(transformationMats.size());
	std::vector<std::vector<double>> d(6);
	for (auto &a : d)
		a.resize(transformationMats.size());
	double hi, hip1;
	for (int i = 1; i < transformationMats.size() - 1; i++)
	{
		hi = fps; // x[i] - x[i - 1];
		hip1 = fps; //  x[i + 1] - x[i];
		m[i] = hi / (hi + hip1);
		l[i] = hip1 / (hi + hip1);
		for (int k = 0; k < 6; k++)
		{
			d[k][i] = 6 / (hi + hip1) * ((transformationMats[i + 1].at<double>(k) - transformationMats[i].at<double>(k)) / hip1
				- (transformationMats[i].at<double>(k) - transformationMats[i - 1].at<double>(k)) / hi);
		}
	}
	for (size_t i = 0; i < coefficients.size(); i++)
	{
		coefficients[i][0] = coefficients[i][transformationMats.size() - 1] = 0;
		la::solveTriDiagonal(&m.data()[1], &b.data()[1], &l.data()[1], &d[i].data()[1], &coefficients[i].data()[1], coefficients[i].size() - 2);
	}
}

cv::Mat SplineInterpolator::interpolate(double x)
{
	cv::Mat mat(2, 3, CV_64FC1);
	int i = (int)ceil(x / fps);	
	if (i == 0)
		i++;
	double hi = fps; // x[i] - x[i - 1];
	for (int k = 0; k < 6; k++)
	{
		mat.at<double>(k)
			= coefficients[k][i - 1] * pow(i*fps - x, 3) / (6 * hi)
			+ coefficients[k][i] * pow(x - (i - 1)*fps, 3) / (6 * hi)
			+ ((transformationMats[i].at<double>(k) - transformationMats[i - 1].at<double>(k)) / hi - (hi / 6) * (coefficients[k][i] - coefficients[k][i - 1])) * (x - (i - 1)*fps)
			+ transformationMats[i - 1].at<double>(k) - coefficients[k][i - 1] * (hi * hi) / 6;
	}
	return mat;
}