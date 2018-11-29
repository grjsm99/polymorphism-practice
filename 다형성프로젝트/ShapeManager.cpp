#include <iostream>
#include "ShapeManager.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <fstream>
using namespace std;

ShapeManager::ShapeManager(int n)
{
	nShape = 0;
	capacity = n;
	shapes = new Shape*[capacity];
}

ShapeManager::~ShapeManager()
{
	// 모든 객체가 정확히 삭제되는지 정확히 확인해야함
	cout << "!!도형들이 삭제됩니다." << endl;
	delete[] shapes;
}

void ShapeManager::insert(Shape* a)
{
	if (nShape<100)
	{
		shapes[nShape] = a;
		nShape++;
		return;
	}
	if(nShape==100)
	{	
		char yesorno=0;
		while (yesorno != 'n' && yesorno != 'y') 
		{ 
			cout << "도형이 꽉차 추가할경우 첫번째 도형이 지워집니다. 계속하시겠습니까? (y/n)" << endl;
			cin >> yesorno;
		}

		if (yesorno == 'n') return;
		for (int i = 0; i < 100; ++i)
		{		
			shapes[i] = shapes[i+1];
		}
		shapes[nShape-1] = a;
	}
};
// if(dynamic_cast<Triangle*>(shapes[i])!=nullptr)
void ShapeManager::delNum(int n)
{
	int key;
	cout << n + 1 << "번째 도형이 제거되었습니다." << endl;
	delete shapes[n];
	for (int i = n; i < nShape-1; ++i)
	{
		shapes[i] = shapes[i + 1];
	}
	nShape--;
	cout << "아무 키나 누르세요.." << endl;
	cin >> key;
};
void ShapeManager::delCls(int n)
{
	int key;
	int delCount = 0;
	switch (n)
	{
	case 1:
		for (int i = 0; i < nShape; ++i)
		{
			if (dynamic_cast<Circle*>(shapes[i]) != nullptr)
			{
				cout << "는 원이다!" << endl;
				delete shapes[i];
				delCount++;
			}
			else
				shapes[i - delCount] = shapes[i];
			}
		nShape -= delCount;
			
		
		break;

	case 2:
		for (int i = 0; i < nShape; ++i)
		{
			if (dynamic_cast<Rectangle*>(shapes[i]) != nullptr)

			{
				cout << i << "는 사각형이다!" << endl;
				delete shapes[i];
				delCount++;
			}
			else
				shapes[i - delCount] = shapes[i];
			}
			nShape -= delCount;
			break;


	case 3:
		for (int i = 0; i < nShape; ++i)
		{
			if (dynamic_cast<Triangle*>(shapes[i]) != nullptr)
			{
				cout << i << "는 삼각형이다!" << endl;
				delete shapes[i];
				delCount++;
			}
			else
				shapes[i-delCount] = shapes[i];

			}

		nShape -= delCount;
		break;
		
	}
	cout << endl << "도형 삭제가 완료되었습니다." << endl;
	cout << "아무 키나 누르세요.." << endl;
	cin >> key;
	
}

void ShapeManager::draw() const
{
	system("cls");
	cout << "----------------------------------------------" << endl;
	cout << "관리하는 모든 도형을 그립니다" << endl;
	cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다" << endl;
	cout << "모두 " << nShape << "개의 도형이 있습니다" << endl;
	cout << "----------------------------------------------" << endl << endl;

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "] ";
		shapes[i]->draw();
		//delete shapes[i];
	}
	cout << endl;

	cout << "----------------------------------------------" << endl;
	cout << "그리기를 마칩니다" << endl;
	cout << "----------------------------------------------" << endl << endl;

}

void ShapeManager::saveShape(int shapeNum)
{
	char* filename = new char[100];
	int shapeType;
	cout << "도형을 저장할 파일의 이름을 적어주세요." << endl;
	cin >> filename;
	ofstream outShape(filename);
		shapes[shapeNum]->saveShape(outShape);
}