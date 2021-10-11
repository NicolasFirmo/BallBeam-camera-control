#include "camera.h"

Camera::Camera(std::string windowName, int cameraIndex) : 
windowName_(std::move(windowName)), cap_(cameraIndex)
{}

void Camera::updateFrame(){
	cap_ >> frame_;
}

void Camera::show(){
	cv::imshow(windowName_, frame_);
}

void Camera::drawROIs(){
	cv::rectangle(frame_, leftSideRoi_, {0xFF,0x00,0xFF});
	cv::rectangle(frame_, rightSideRoi_, {0xFF,0x00,0xFF});
}

Rod Camera::getRod(){
	return Rod{getCenter(leftSideRoi_, {0x9F, 0x10, 0x8F}, {0x30, 0x10, 0x40}),
			getCenter(rightSideRoi_, {0x9F, 0x10, 0x8F}, {0x30, 0x10, 0x40})};
}

Point Camera::getCenter(const cv::Rect& roi, const cv::Scalar& targetColor,
		const cv::Scalar& colorError){
	Point centerSum{0, 0};
	int pixelCount = 0;
	frame_(roi).forEach<cv::Point3d>([&](cv::Point3d& pixelColor, const int* position){
		if(colorInRange(pixelColor, targetColor, colorError)){
			centerSum.x += position[0];
			centerSum.y += position[1];
			pixelCount++;
		}
	});
	return centerSum / pixelCount;
}

bool Camera::colorInRange(const cv::Point3d& pixel, const cv::Scalar& targetColor,
		const cv::Scalar& colorError) const{
	return pixel.x >= targetColor[0] - colorError[0] &&  pixel.x <= targetColor[0] + colorError[0] &&
		pixel.y >= targetColor[1] - colorError[1] &&  pixel.y <= targetColor[1] + colorError[1] &&
		pixel.z >= targetColor[2] - colorError[2] &&  pixel.z <= targetColor[2] + colorError[2];
}
