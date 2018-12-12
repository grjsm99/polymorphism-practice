#include "Shape.h"

class ShapeManager {
	int nShape;			// 도형의 갯수
	int capacity;		// 담을수 있는 최대 도형갯수 
	Shape** shapes;		// 도형의 포인터들을 담을수 있는 메모리
public:
	explicit ShapeManager(int n);	// explicit 알아두기, 담을수 있는 도형의 갯수가 인자인 생성자

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;
	
	void insert(Shape*);	// 도형을 추가하는 함수
	void draw() const;		// 전체도형을 그리는 함수
	void delNum(int); // 도형을 삭제하는 함수
	void delCls(int);

};