#include "VideoInterpolator.hpp"

VideoInterpolator::VideoInterpolator(cv::Mat firstImage, std::vector<cv::Mat> transformationMats, double originalFps, std::unique_ptr<Interpolator> interpolator) :
	transformationMats(transformationMats), interpolator(std::move(interpolator)), originalFps(originalFps)
{
	this->firstImage = firstImage.clone();
}

VideoInterpolator::~VideoInterpolator()
{
}

bool VideoInterpolator::createOriginalVideo(std::string filename)
{
	cv::Mat dst = cv::Mat(firstImage.size(), firstImage.type());
	cv::VideoWriter video(filename, CV_FOURCC('M', 'J', 'P', 'G'), originalFps, firstImage.size());
	if (!video.isOpened())
		return false;
	int i = 0;
	for (auto m : transformationMats)
	{
		dst.setTo(cv::Scalar(255, 255, 255));
		la::transformImage(firstImage, dst, m);
		video.write(dst);
	}
	video.release();
	return true;
}

bool VideoInterpolator::createInterpolateVideo(std::string filename)
{
	cv::Mat dst = cv::Mat(firstImage.size(), firstImage.type());
	cv::VideoWriter video(filename, CV_FOURCC('M', 'J', 'P', 'G'), originalFps * interpolator->getFps(), firstImage.size());
	if (!video.isOpened())
		return false;
	for (size_t i = 0; i <= interpolator->getFps() * (int)(transformationMats.size() - 1); i++)
	{
		dst.setTo(cv::Scalar(255, 255, 255));
		la::transformImage(firstImage, dst, interpolator->interpolate((double)i));
		video.write(dst);
	}
	video.release();
	return true;
}

bool VideoInterpolator::setInterpolator(std::unique_ptr<Interpolator> interpolator)
{
	this->interpolator = std::move(interpolator);
	return true;
}
