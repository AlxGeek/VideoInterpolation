#include "LinearAlgebra.hpp"


namespace la
{

	bool solveTriDiagonal(const double* a, const double* b, const double* c, const double* d, double* x, const size_t n)
	{
		std::vector<double> ab(n);
		std::vector<double> bb(n);
		std::vector<double> cb(n);
		std::vector<double> db(n);
		bb[0] = b[0];
		cb[0] = c[0];
		db[0] = d[0];
		for (int i = 1; i < n; i++)
		{
			bb[i] = bb[i - 1] * b[i] - a[i] * cb[i - 1];
			cb[i] = bb[i - 1] * c[i];
			db[i] = bb[i - 1] * d[i] - a[i] * db[i - 1];
		}
		if (fabs(bb[n - 1]) < 0.000001)
		{
			return false;
		}
		x[n - 1] = db[n - 1] / bb[n - 1];
		//Don't fix this warning
		for (int i = n - 2; i >= 0; i--)
		{
			if (fabs(bb[i]) < 0.000001)
			{
				return false;
			}

			x[i] = (db[i] - cb[i] * x[i + 1]) / bb[i];
		}
		return true;
	}


	void transformImage(cv::Mat input, cv::Mat &output, cv::Mat transMat) {
		for (int i = 0; i < input.rows; i++)
		{
			for (int j = 0; j < input.cols; j++)
			{
				int iIn = (int)(i * transMat.at<double>(0, 0) + j * transMat.at<double>(0, 1) + transMat.at<double>(0, 2));
				int jIn = (int)(i * transMat.at<double>(1, 0) + j * transMat.at<double>(1, 1) + transMat.at<double>(1, 2));
				if (iIn < 0 || iIn >= input.rows || jIn < 0 || jIn >= input.cols) {
					continue;
				}
				output.at<cv::Vec3b>(iIn, jIn) = input.at<cv::Vec3b>(i, j);
			}
		}
	}

	cv::Mat getDifferenceMat(cv::Mat m1, cv::Mat m2, size_t n) {
		cv::Mat dMat(2, 3, CV_64FC1);
		dMat.at<double>(0, 0) = (m2.at<double>(0, 0) - m1.at<double>(0, 0)) / n;
		dMat.at<double>(0, 1) = (m2.at<double>(0, 1) - m1.at<double>(0, 1)) / n;
		dMat.at<double>(0, 2) = (m2.at<double>(0, 2) - m1.at<double>(0, 2)) / n;
		dMat.at<double>(1, 0) = (m2.at<double>(1, 0) - m1.at<double>(1, 0)) / n;
		dMat.at<double>(1, 1) = (m2.at<double>(1, 1) - m1.at<double>(1, 1)) / n;
		dMat.at<double>(1, 2) = (m2.at<double>(1, 2) - m1.at<double>(1, 2)) / n;
		return dMat;
	}

	cv::Mat createTransformationMat(double angle, cv::Point2i center, double tx, double ty) {
		cv::Mat mat(2, 3, CV_64FC1);
		angle *= M_PI / 180;
		double a = cos(angle);
		double b = sin(angle);
		mat.at<double>(0, 0) = a;
		mat.at<double>(0, 1) = b;
		mat.at<double>(0, 2) = (1 - a) * center.x - b * center.y + ty;
		mat.at<double>(1, 0) = -b;
		mat.at<double>(1, 1) = a;
		mat.at<double>(1, 2) = b * center.x + (1 - a) * center.y + tx;
		return mat;
	}


}