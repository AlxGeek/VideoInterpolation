#include <iostream>

#include <opencv2/core/core.hpp>

#include "VideoInterpolator.hpp"
#include "SplineInterpolator.hpp"
#include "LinearInterpolator.hpp"

void joinTwoVideo(std::string filename1, std::string filename2, std::string filenameVideo) {
	cv::VideoCapture video1(filename1);
	cv::VideoCapture video2(filename2);
	cv::VideoWriter video(filenameVideo, CV_FOURCC('M', 'J', 'P', 'G'), video1.get(CV_CAP_PROP_FPS), cv::Size(video1.get(CV_CAP_PROP_FRAME_WIDTH),  2 * video1.get(CV_CAP_PROP_FRAME_HEIGHT)));
	cv::Mat img1, img2;
	cv::Mat imgVideo;
	while(video1.read(img1)){
		video2.read(img2);
		cv::vconcat(img1, img2, imgVideo);
		video << imgVideo;
	}
}

void example1(cv::Mat &firstImage, std::vector<cv::Mat> &transformationMats) {
	firstImage = cv::imread("image.png");
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
}

void example2(cv::Mat &firstImage, std::vector<cv::Mat> &transformationMats) {
	firstImage = cv::imread("image2.png");
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, 0, 0));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .3, firstImage.rows * .0));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .6, firstImage.rows * .0));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .6, firstImage.rows * .3));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .6, firstImage.rows * 0.6));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .3, firstImage.rows * .6));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .0, firstImage.rows * .6));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .0, firstImage.rows * .3));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, 0, 0));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .3, firstImage.rows * .3));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .6, firstImage.rows * 0.6));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .6, firstImage.rows * .3));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .6, firstImage.rows * .0));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .3, firstImage.rows * .3));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .0, firstImage.rows * .6));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * .0, firstImage.rows * .3));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, 0, 0));
}

void example3(cv::Mat &firstImage, std::vector<cv::Mat> &transformationMats) {
	firstImage = cv::imread("image3.png");
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * 0, -firstImage.rows * .3));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * 0, -firstImage.rows * .1));
	//transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, 0, 0));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * 0, firstImage.rows * .1));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * 0, firstImage.rows * .3));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * 0, firstImage.rows * .5));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * 0, firstImage.rows * .5));
	transformationMats.push_back(la::createTransformationMat(0, { firstImage.cols / 2, firstImage.rows / 2 }, firstImage.cols * 0, firstImage.rows * .5));
	
}

int main(int argc, char** argv) {

	cv::Mat firstImage;
	std::vector<cv::Mat> transformationMats;
	example2(firstImage, transformationMats);
	
	VideoInterpolator imageInterpolator(firstImage, transformationMats, 2, std::make_unique<LinearInterpolator>(transformationMats, 10));
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
	std::cout << "Combinando videos interpolados..." << std::endl;	
	joinTwoVideo("video_lineal.avi", "video_spline.avi", "video_comb.avi");
	std::cout << "Video combinado creado." << std::endl;


	return 0;
}