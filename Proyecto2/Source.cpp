#include <iostream>

#include <opencv2/core/core.hpp>

#include "VideoInterpolator.hpp"
#include "SplineInterpolator.hpp"
#include "LinearInterpolator.hpp"

int main(int argc, char** argv) {
	cv::Mat firstImage = cv::imread("image.png");

	std::vector<cv::Mat> transformationMats;
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, 0, 0));
	transformationMats.push_back(la::createTransformationMat(15, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .05, firstImage.rows * .05));
	transformationMats.push_back(la::createTransformationMat(5, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .10, firstImage.rows * .10));
	transformationMats.push_back(la::createTransformationMat(10, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .20, firstImage.rows * .30));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .27, firstImage.rows * .45));
	transformationMats.push_back(la::createTransformationMat(15, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .20, firstImage.rows * .57));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .55, firstImage.rows * .63));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .60, firstImage.rows * .69));
	transformationMats.push_back(la::createTransformationMat(5, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .68, firstImage.rows * .60));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .70, firstImage.rows * .53));
	transformationMats.push_back(la::createTransformationMat(15, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .73, firstImage.rows * .5));


	VideoInterpolator imageInterpolator(firstImage, transformationMats, 3, std::make_unique<LinearInterpolator>(transformationMats, 10));
	std::cout << "Creando video original..." << std::endl;
	imageInterpolator.createOriginalVideo("video_original.avi");
	std::cout << "Video original creado." << std::endl;
	std::cout << "Creando video interpolado con linear..." << std::endl;
	imageInterpolator.createInterpolateVideo("video_lineal.avi");
	std::cout << "Video interpolado creado." << std::endl;
	imageInterpolator.setInterpolator(std::make_unique<SplineInterpolator>(transformationMats, 10));
	std::cout << "Creando video interpolado con spline..." << std::endl;
	imageInterpolator.createInterpolateVideo("video_spline.avi");
	std::cout << "Video interpolado creado." << std::endl;


	return 0;
}