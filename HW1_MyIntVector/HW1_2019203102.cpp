//2019203102 유지성

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

	cout << "2019203102 유지성 HW1\n";
	cout << "=========================================================\n";
	cout << "MyIntVector\n";
	cout << "=========================================================\n";


	cout << "push_back을 이용해 v1에 1, 2, 3 추가\n";
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout << "v1 : ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\npop_back을 이용해 v1의 마지막 요소 제거\n";
	v1.pop_back();
	cout << "v1 : ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";

	cout << "\n\ncapacity를 이용해 v1의 space 출력 : " << v1.capacity() << "\n";
	cout << "size를 이용해 v1의 used 출력 : " << v1.size() << "\n";

	cout << "\npush_back을 이용해 v1에 DEFAULT_CAPACITY보다 많은 값을 추가\n";
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
	cout << "\nDEFAULT_CAPACITY보다 많은 값을 추가한 후 v1의 capcity와 size\n";
	cout << "capacity : " << v1.capacity() << "\tsize : " << v1.size() << "\n";
	
	cout << "=========================================================";
	
	cout << "\nis_empty를 이용해 v1과 v2가 비어있는지 확인\n";
	if (v1.is_empty())
		cout << "v1 is empty\n";
	else
		cout << "v1 is not empty\n";
	if (v2.is_empty())
		cout << "v2 is empty\n";
	else
		cout << "v2 is not empty\n";

	cout << "\nclear를 이용해 v1을 clear\n";
	v1.clear();
	cout << "v1이 비어있는지 확인\n";
	if (v1.is_empty())
		cout << "v1 is empty\n";
	else
		cout << "v1 is not empty\n";
	cout << "capacity : " << v1.capacity() << "\tsize : " << v1.size() << "\n";

	cout << "=========================================================";

	cout << "\nv1벡터에 0~9까지의 값 할당 후 MyIntVector(const MyIntVector& v)를 이용해 v3에 복사\n";
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	MyIntVector v3(v1);
	cout << "v1 : ";
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << "\nv3 : ";
	for (int i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";

	cout << "\n\n= operator를 이용해 v2에 v1 복사\n";
	v2 = v1;
	cout << "v2 : ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	cout << "\n\n+= operator를 이용해 v2에 v1 추가\n";
	v2 += v1;
	cout << "v2 : ";
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";

	cout << "\n\n[] operator를 이용해 v1의 0번, 3번, 7번 요소 출력\n";
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