#ifndef _Point
#define _Point

struct Point	// ������� public���� ��.
{
	double x, y;

	Point();
	Point(double, double);
	Point(const Point&) = default; // �����ʿ䰡 ����.
};


#endif