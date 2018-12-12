#include "Shape.h"

class ShapeManager {
	int nShape;			// ������ ����
	int capacity;		// ������ �ִ� �ִ� �������� 
	Shape** shapes;		// ������ �����͵��� ������ �ִ� �޸�
public:
	explicit ShapeManager(int n);	// explicit �˾Ƶα�, ������ �ִ� ������ ������ ������ ������

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;
	
	void insert(Shape*);	// ������ �߰��ϴ� �Լ�
	void draw() const;		// ��ü������ �׸��� �Լ�
	void delNum(int); // ������ �����ϴ� �Լ�
	void delCls(int);

};