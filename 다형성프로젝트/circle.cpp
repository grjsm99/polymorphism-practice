#include <iostream>
#include "Circle.h"
#include <fstream>

Circle::Circle() : center(), rad(0) {}

Circle::Circle(const Point& c, int r) : center(c), rad(r) { std::cout << "�� ����" << std::endl; }

Circle::Circle(const Circle& other) : center(other.center), rad(other.rad) {  };

Circle::~Circle() { std::cout << "�� �Ҹ�" << std::endl; }

void Circle::draw() const
{
	std::cout << "�� - �߽���(" << center.x << "," << center.y << ") ������ " << rad << std::endl;
}
