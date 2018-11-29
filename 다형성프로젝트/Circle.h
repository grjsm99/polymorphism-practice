#include "Point.h"
#include "Shape.h"
using namespace std;
class Circle : public Shape
{
	Point center;	// �߽��� ��ǥ
	int rad;		// ������
public:
	Circle();
	Circle(const Point&, int);
	Circle(const Circle&);		// �������� ������ ���ٸ� ��������ڸ� ���α׷��� �ʿ�� ����.
	virtual ~Circle();

	virtual void draw() const override;
	virtual void saveShape(ofstream&) const override;
};