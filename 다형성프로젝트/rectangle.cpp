#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() : p1(), p2() {};
Rectangle::Rectangle(const Point& a, const Point& b) : p1(a), p2(b) { std::cout << "�簢�� ����" << std::endl; };
Rectangle::Rectangle(const Rectangle& other) : p1(other.p1), p2(other.p2) {};
Rectangle::~Rectangle() { std::cout << "�簢�� �Ҹ�" << std::endl; };
void Rectangle::draw() const 
{
	std::cout << "�簢�� - (" << p1.x << "," << p1.y << "), (" << p2.x << "," << p2.y << ")" << std::endl;
}
