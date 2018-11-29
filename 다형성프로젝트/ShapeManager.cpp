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
	// ��� ��ü�� ��Ȯ�� �����Ǵ��� ��Ȯ�� Ȯ���ؾ���
	cout << "!!�������� �����˴ϴ�." << endl;
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
			cout << "������ ���� �߰��Ұ�� ù��° ������ �������ϴ�. ����Ͻðڽ��ϱ�? (y/n)" << endl;
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
	cout << n + 1 << "��° ������ ���ŵǾ����ϴ�." << endl;
	delete shapes[n];
	for (int i = n; i < nShape-1; ++i)
	{
		shapes[i] = shapes[i + 1];
	}
	nShape--;
	cout << "�ƹ� Ű�� ��������.." << endl;
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
				cout << "�� ���̴�!" << endl;
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
				cout << i << "�� �簢���̴�!" << endl;
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
				cout << i << "�� �ﰢ���̴�!" << endl;
				delete shapes[i];
				delCount++;
			}
			else
				shapes[i-delCount] = shapes[i];

			}

		nShape -= delCount;
		break;
		
	}
	cout << endl << "���� ������ �Ϸ�Ǿ����ϴ�." << endl;
	cout << "�ƹ� Ű�� ��������.." << endl;
	cin >> key;
	
}

void ShapeManager::draw() const
{
	system("cls");
	cout << "----------------------------------------------" << endl;
	cout << "�����ϴ� ��� ������ �׸��ϴ�" << endl;
	cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�" << endl;
	cout << "��� " << nShape << "���� ������ �ֽ��ϴ�" << endl;
	cout << "----------------------------------------------" << endl << endl;

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "] ";
		shapes[i]->draw();
		//delete shapes[i];
	}
	cout << endl;

	cout << "----------------------------------------------" << endl;
	cout << "�׸��⸦ ��Ĩ�ϴ�" << endl;
	cout << "----------------------------------------------" << endl << endl;

}

void ShapeManager::saveShape(int shapeNum)
{
	char* filename = new char[100];
	int shapeType;
	cout << "������ ������ ������ �̸��� �����ּ���." << endl;
	cin >> filename;
	ofstream outShape(filename);
		shapes[shapeNum]->saveShape(outShape);
}