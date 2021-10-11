#pragma once

struct Point{
	float x, y;

	Point operator+(const Point& rhs){ return {x + rhs.x, y + rhs.y}; }
	Point operator-(const Point& rhs){ return {x - rhs.x, y - rhs.y}; }
	Point operator*(float rhs){ return {x * rhs, y * rhs}; }
	Point operator/(float rhs){ return {x / rhs, y / rhs}; }
};
