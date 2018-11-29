#ifndef _Shape
#define _Shape
using namespace std;
class Shape
{
public:
	Shape() {};
	virtual ~Shape() {  };

	virtual void draw() const = 0;	// 가상 함수
	virtual void saveShape(ofstream&) const=0;
};




#endif // !_Shape