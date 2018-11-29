#include "point.h"
#include "shape.h"
using namespace std;
class Triangle : public Shape
{
	Point p1, p2, p3;
public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	virtual ~Triangle();

	virtual void draw() const override;	// 가상함수 overriding
	virtual void saveShape(ofstream&) const override;
};