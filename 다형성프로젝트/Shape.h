#ifndef _Shape
#define _Shape
using namespace std;
class Shape
{
public:
	Shape() {};
	virtual ~Shape() {  };

	virtual void draw() const = 0;	// ���� �Լ�

};




#endif // !_Shape