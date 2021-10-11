#pragma once
#include "rod.h"
#include "ball.h"

class Camera{
public:
	Camera(std::string windowName, int cameraIndex = 0);

	void updateFrame();
	void show();

	void drawROIs();

	Rod getRod() const;
	Ball getBall() const;

	const std::string& getName() const {return windowName_;}

private:
	Point getCenter(const cv::Rect& roi, const cv::Scalar& color,
		const cv::Scalar& colorError) const;
	bool colorInRange(const cv::Point3d& pixel, const cv::Scalar& targetColor,
        const cv::Scalar& colorError) const;

private:
	std::string windowName_;
	cv::VideoCapture cap_;
	cv::Mat frame_;

	const cv::Rect leftSideRoi_ {40,130,120,200};
	const cv::Rect rightSideRoi_ {500,130,120,200};
};
