#include "point.h"
#include "shape.h"
using namespace std;
class Rectangle : public Shape
{
	Point p1, p2;
public:
	Rectangle();
	Rectangle(const Point&, const Point&);
	Rectangle(const Rectangle&);
	virtual ~Rectangle();
	

	virtual void draw() const override;
	virtual void saveShape(ofstream&) const override;
};

