#include "rod.h"

Rod::Rod(Point left, Point right):
left_(std::move(left)), right_(std::move(right))
{}

float Rod::getLevel() const {
	return left_.y - right_.y;
}

void Rod::setPoints(Point left, Point right){
	left_ = left;
	right_ = right;
}
