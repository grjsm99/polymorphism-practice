#include <iostream>
#include "Circle.h"
#include <fstream>

Circle::Circle() : center(), rad(0) {}

Circle::Circle(const Point& c, int r) : center(c), rad(r) { std::cout << "원 생성" << std::endl; }

Circle::Circle(const Circle& other) : center(other.center), rad(other.rad) {  };

Circle::~Circle() { std::cout << "원 소멸" << std::endl; }

void Circle::draw() const
{
	std::cout << "원 - 중심점(" << center.x << "," << center.y << ") 반지름 " << rad << std::endl;
}
