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

	
	// 1. ���� Ŭ������ ����.
	ShapeManager sm(100);	// �ִ� 100���� ��������
	/*sm.insert(new Circle(Point(1,1), 1));
	sm.insert(new Circle(Point(1, 1), 2));
	sm.insert(new Circle(Point(1, 1), 3));
	sm.insert(new Circle(Point(1, 1), 4));
	*/
	for (int i = 0; i < 100; ++i)
		sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));
	mainMenu(sm);
	// 2. �������� ���� Ŭ������ ����

	
	

	// 3. �����ϰ� �ִ� ��� ������ �׸�
	sm.draw();

	
}

void mainMenu(ShapeManager& sh) {

	int key=0;
	while (key!=6) {
		system("cls");
		cout << "----------------------------------------------" << endl;
		cout << "���Ͻô� �׸��� �������ּ���." << endl;
		cout << "----------------------------------------------" << endl << endl;

		cout << "----------------------------------------------" << endl << endl;
		cout << "\t" << "1 - ���ϴ� ���� �߰�" << endl << endl;
		cout << "\t" << "2 - ��ü ������ �׸���" << endl << endl;
		cout << "\t" << "3 - ���� �����ϱ�" << endl << endl;	
		cout << "\t" << "4 - ���Ͽ� ���� �����ϱ�" << endl << endl;
		cout << "\t" << "5 - ���Ͽ��� ���� �о����" << endl << endl;
		cout << "\t" << "6 - ���α׷� ������" << endl << endl;
		cout << "----------------------------------------------" << endl << endl;
		
		cin >> key;

		switch (key)
		{
		case 1:
			selectShape(sh);
			break;
		case 2:
			sh.draw();
			cout << "�ƹ� Ű�� ��������.." << endl;
			cin >> key;
			break;
		case 3:
			deleteShape(sh);
			break;
		case 4:
			int selectSh;
			sh.draw();
			cout << " ��� ������ �����Ͻðھ��? " << endl;
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
	cout << "���Ͻô� ������ ����� ����ּ���." << endl << endl;
	cout << "1 - ��" << endl;
	cout << "2 - �簢��" << endl;
	cout << "3 - �ﰢ��" << endl;
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
	cout << "���� �߽� ��ǥ�� �Է����ּ���." << endl << "x = ";
	cin >> circleO.x;
	cout << "y = ";
	cin >> circleO.y;
	cout << "���� �������� �Է����ּ���" << endl;
	cin >> circleR;
	sh.insert(new Circle(circleO, circleR));
}

void insertRectangle(ShapeManager& sh)
{
	Point rect1;
	Point rect2;
	cout << "�簢���� ù��° �������� ��ǥ�� �Է����ּ���." << endl << "x = ";
	cin >> rect1.x;
	cout << "y = ";
	cin >> rect1.y;
	cout << "�簢���� �ι�° �������� ��ǥ�� �Է����ּ���." << endl << "x = ";
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
	cout << "�ﰢ���� ù��° �������� ��ǥ�� �Է����ּ���." << endl << "x = ";
	cin >> tri1.x;
	cout << "y = ";
	cin >> tri1.y;
	cout << "�ﰢ���� �ι�° �������� ��ǥ�� �Է����ּ���." << endl << "x = ";
	cin >> tri2.x;
	cout << "y = ";
	cin >> tri2.y;
	cout << "�ﰢ���� ����° �������� ��ǥ�� �Է����ּ���." << endl << "x = ";
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
	cout << "���Ͻô� �ɼ��� ����ּ���." << endl << endl;
	cout << "1 - ��ȣ�� ����" << endl;
	cout << "2 - Ŭ���� ����" << endl;
	cout << "----------------------------------------------" << endl << endl;
	cin >> menuSelect;
	switch (menuSelect)
	{
		int num;
	case 1:
		
		cout << "���° ������ �����ұ��?" << endl;
		cin >> num;
		sh.delNum(num-1);	
		break;
	case 2:
		cout << "���� ������ �����ұ��?" << endl << "1 - ��, 2 - �簢��, 3 - �ﰢ��" << endl;
		cin >> num;
		sh.delCls(num);
		break;
	}
	
}
