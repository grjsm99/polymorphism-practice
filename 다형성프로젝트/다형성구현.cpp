#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "ShapeManager.h"
#include <iostream>
#include <fstream>

using namespace std;

void mainMenu(ShapeManager&);
void selectShape(ShapeManager&);
void deleteShape(ShapeManager&);
void insertCircle(ShapeManager&);
void insertRectangle(ShapeManager&);
void insertTriangle(ShapeManager&);
void saveShape(ostream&);
int main()
{

	
	// 1. 관리 클래스를 만듦.
	ShapeManager sm(100);	// 최대 100개의 도형관리
	/*sm.insert(new Circle(Point(1,1), 1));
	sm.insert(new Circle(Point(1, 1), 2));
	sm.insert(new Circle(Point(1, 1), 3));
	sm.insert(new Circle(Point(1, 1), 4));
	*/
	for (int i = 0; i < 100; ++i)
		sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));
	mainMenu(sm);
	// 2. 도형들을 관리 클래스에 삽입

	
	

	// 3. 관리하고 있는 모든 도형을 그림
	sm.draw();

	
}

void mainMenu(ShapeManager& sh) {

	int key=0;
	while (key!=6) {
		system("cls");
		cout << "----------------------------------------------" << endl;
		cout << "원하시는 항목을 선택해주세요." << endl;
		cout << "----------------------------------------------" << endl << endl;

		cout << "----------------------------------------------" << endl << endl;
		cout << "\t" << "1 - 원하는 도형 추가" << endl << endl;
		cout << "\t" << "2 - 전체 도형을 그리기" << endl << endl;
		cout << "\t" << "3 - 도형 제거하기" << endl << endl;	
		cout << "\t" << "4 - 파일에 도형 저장하기" << endl << endl;
		cout << "\t" << "5 - 파일에서 도형 읽어오기" << endl << endl;
		cout << "\t" << "6 - 프로그램 끝내기" << endl << endl;
		cout << "----------------------------------------------" << endl << endl;
		
		cin >> key;

		switch (key)
		{
		case 1:
			selectShape(sh);
			break;
		case 2:
			sh.draw();
			cout << "아무 키나 누르세요.." << endl;
			cin >> key;
			break;
		case 3:
			deleteShape(sh);
			break;
		case 4:
			int selectSh;
			sh.draw();
			cout << " 몇번 도형을 저장하시겠어요? " << endl;
			cin >> selectSh;
			
	

			break;
		case 5:
			break;
			
		case 6:
			break;

		}
	}
};
void selectShape(ShapeManager& sh) {
	int ShapeType;
	
	system("cls");
	cout << "----------------------------------------------" << endl;
	cout << "원하시는 도형의 모양을 골라주세요." << endl << endl;
	cout << "1 - 원" << endl;
	cout << "2 - 사각형" << endl;
	cout << "3 - 삼각형" << endl;
	cout << "----------------------------------------------" << endl << endl;

	cin >> ShapeType;

	switch (ShapeType)
	{
	case 1:
		insertCircle(sh);
		break;
	case 2:
		insertRectangle(sh);
		break;
	case 3:
		insertTriangle(sh);
		break;
	}



}
void insertCircle(ShapeManager& sh)
{
	Point circleO;
	int circleR;
	cout << "원의 중심 좌표를 입력해주세요." << endl << "x = ";
	cin >> circleO.x;
	cout << "y = ";
	cin >> circleO.y;
	cout << "원의 반지름을 입력해주세요" << endl;
	cin >> circleR;
	sh.insert(new Circle(circleO, circleR));
}

void insertRectangle(ShapeManager& sh)
{
	Point rect1;
	Point rect2;
	cout << "사각형의 첫번째 꼭짓점의 좌표를 입력해주세요." << endl << "x = ";
	cin >> rect1.x;
	cout << "y = ";
	cin >> rect1.y;
	cout << "사각형의 두번째 꼭짓점의 좌표를 입력해주세요." << endl << "x = ";
	cin >> rect2.x;
	cout << "y = ";
	cin >> rect2.y;
	sh.insert(new Rectangle(rect1, rect2));
}

void insertTriangle(ShapeManager& sh)
{
	Point tri1;
	Point tri2;
	Point tri3;
	cout << "삼각형의 첫번째 꼭짓점의 좌표를 입력해주세요." << endl << "x = ";
	cin >> tri1.x;
	cout << "y = ";
	cin >> tri1.y;
	cout << "삼각형의 두번째 꼭짓점의 좌표를 입력해주세요." << endl << "x = ";
	cin >> tri2.x;
	cout << "y = ";
	cin >> tri2.y;
	cout << "삼각형의 세번째 꼭짓점의 좌표를 입력해주세요." << endl << "x = ";
	cin >> tri3.x;
	cout << "y = ";
	cin >> tri3.y;

	sh.insert(new Triangle(tri1, tri2, tri3));
}

void deleteShape(ShapeManager& sh)
{
	int menuSelect;
	system("cls");
	cout << "----------------------------------------------" << endl;
	cout << "원하시는 옵션을 골라주세요." << endl << endl;
	cout << "1 - 번호로 제거" << endl;
	cout << "2 - 클래스 제거" << endl;
	cout << "----------------------------------------------" << endl << endl;
	cin >> menuSelect;
	switch (menuSelect)
	{
		int num;
	case 1:
		
		cout << "몇번째 도형을 제거할까요?" << endl;
		cin >> num;
		sh.delNum(num-1);	
		break;
	case 2:
		cout << "무슨 도형을 제거할까요?" << endl << "1 - 원, 2 - 사각형, 3 - 삼각형" << endl;
		cin >> num;
		sh.delCls(num);
		break;
	}
	
}
