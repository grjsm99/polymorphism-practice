#ifndef _Point
#define _Point

struct Point	// 모든멤버를 public으로 함.
{
	double x, y;

	Point();
	Point(double, double);
	Point(const Point&) = default; // 만들필요가 없다.
};


#endif