#pragma once

#define _USE_MATH_DEFINES
#include <cmath> 

#include <vector>
#include <memory>

#include <opencv2/videoio/videoio.hpp>
#include <opencv2/core/core.hpp>

#include "LinearAlgebra.hpp"
#include "Interpolator.hpp"

class VideoInterpolator
{
private:
	cv::Mat firstImage;
	std::unique_ptr<Interpolator> interpolator;
	std::vector<cv::Mat> transformationMats;
	double originalFps;	

public:
	VideoInterpolator(cv::Mat firstImage, std::vector<cv::Mat> transformationMats, double originalFps, std::unique_ptr<Interpolator> interpolator);
	~VideoInterpolator();

	bool createOriginalVideo(std::string filename);
	bool createInterpolateVideo(std::string filename);

	bool setInterpolator(std::unique_ptr<Interpolator> interpolator);

};

