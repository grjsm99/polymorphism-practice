#include "Point.h"
#include "Shape.h"
using namespace std;
class Circle : public Shape
{
	Point center;	// 중심점 좌표
	int rad;		// 반지름
public:
	Circle();
	Circle(const Point&, int);
	Circle(const Circle&);		// 깊은복사 할일이 없다면 복사생성자를 프로그램할 필요는 없다.
	virtual ~Circle();

	virtual void draw() const override;
	virtual void saveShape(ofstream&) const override;
};