//2019203102 ������

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <algorithm>    
#include <cassert>       
#include "MyIntVector.h"
using namespace std;

int main() {
	MyIntVector v1;
	MyIntVector v2;

	cout << "2019203102 ������ HW1\n";
	cout << "=========================================================\n";
	cout << "MyIntVector\n";
	cout << "=========================================================\n";


	cout << "push_back�� �̿��� v1�� 1, 2, 3 �߰�\n";
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout << "v1 : ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\npop_back�� �̿��� v1�� ������ ��� ����\n";
	v1.pop_back();
	cout << "v1 : ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\n\ncapacity�� �̿��� v1�� space ��� : " << v1.capacity() << "\n";
	cout << "size�� �̿��� v1�� used ��� : " << v1.size() << "\n";

	cout << "\npush_back�� �̿��� v1�� DEFAULT_CAPACITY���� ���� ���� �߰�\n";
	cout << "v1 : \n";
	for (int i = 0; i < 33; i++)
	{
		v1.push_back(0);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
		if ((i + 1) % 10 == 0 )
			cout << "\n";
	}
	cout << "\nDEFAULT_CAPACITY���� ���� ���� �߰��� �� v1�� capcity�� size\n";
	cout << "capacity : " << v1.capacity() << "\tsize : " << v1.size() << "\n";
	
	cout << "=========================================================";
	
	cout << "\nis_empty�� �̿��� v1�� v2�� ����ִ��� Ȯ��\n";
	if (v1.is_empty())
		cout << "v1 is empty\n";
	else
		cout << "v1 is not empty\n";
	if (v2.is_empty())
		cout << "v2 is empty\n";
	else
		cout << "v2 is not empty\n";

	cout << "\nclear�� �̿��� v1�� clear\n";
	v1.clear();
	cout << "v1�� ����ִ��� Ȯ��\n";
	if (v1.is_empty())
		cout << "v1 is empty\n";
	else
		cout << "v1 is not empty\n";
	cout << "capacity : " << v1.capacity() << "\tsize : " << v1.size() << "\n";

	cout << "=========================================================";

	cout << "\nv1���Ϳ� 0~9������ �� �Ҵ� �� MyIntVector(const MyIntVector& v)�� �̿��� v3�� ����\n";
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	MyIntVector v3(v1);
	cout << "v1 : ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << "\nv3 : ";
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	cout << "\n\n= operator�� �̿��� v2�� v1 ����\n";
	v2 = v1;
	cout << "v2 : ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	cout << "\n\n+= operator�� �̿��� v2�� v1 �߰�\n";
	v2 += v1;
	cout << "v2 : ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	cout << "\n\n[] operator�� �̿��� v1�� 0��, 3��, 7�� ��� ���\n";
	cout << "v1[0] : " << v1[0] << "\tv1[3] : " << v1[3] << "\tv1[7] : " << v1[7] << "\n";
	cout << "=========================================================";

	cout << "\n+, -, *, -(unary), ==, ()operator\n\n";
	cout << "v1 : ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << "\nv2 : ";
	v2.clear();
	for (int i = 0; i < 10; i++)
		v2.push_back(i % 4 + 1);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	
	cout << "\n\n+\n";
	cout << "v1 + v2 : \n";
	v3 = v1 + v2;
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	cout << "\n\n-\n";
	cout << "v1 - v2 : \n";
	v3 = v1 - v2;
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	cout << "\n\n*\n";
	cout << "v1 * v2 : \n";
	int t = v1 * v2;
	cout << t;

	cout << "\n\n-(unary)\n";
	cout << "-v1 : \n";
	v3 = -v1;
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	cout << "\n\n==\n";
	cout << "v1 == v2 : \n";
	if (v1 == v2)
		cout << "v1 equals v2";
	else
		cout << "v1 not equals v2";

	cout << "\n\n()\n";
	cout << "v1(3) : \n";
	v3 = v1(3);
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	return 0;
}