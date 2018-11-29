#include <iostream>
#include "triangle.h"
#include <fstream>
Triangle::Triangle() : p1(), p2(), p3() {  };

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : p1(a), p2(b), p3(c) { std::cout << "»ï°¢Çü »ý¼º" << std::endl; };

Triangle::Triangle(const Triangle& other) : p1(other.p1), p2(other.p2), p3(other.p3) {	};

Triangle::~Triangle() { std::cout << "»ï°¢Çü ¼Ò¸ê" << std::endl; };
void Triangle::draw() const
{
	std::cout << "»ï°¢Çü - (" << p1.x << "," << p1.y << "), (" << p2.x << "," << p2.y << "), (" << p3.x << "," << p3.y << ")" << std::endl;
}
void Triangle::saveShape(std::ofstream& of) const
{

}