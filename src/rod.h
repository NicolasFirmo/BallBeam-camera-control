#pragma once
#include "point.h"

class Rod{
public:
	Rod(Point left, Point right);

	float getLevel() const;

	void setPoints(Point left, Point right);

	Point getLeftPoint() const {return left_;}
	Point getRightPoint() const {return right_;}
private:
	Point left_, right_;
};
