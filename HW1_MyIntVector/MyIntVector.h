//2019203102 ������

#include <cstdlib>
#include <stdlib.h>
#include <algorithm>    
#include <cassert>       

class MyIntVector {
public:
	static const size_t DEFAULT_CAPACITY = 30;

	MyIntVector();
	MyIntVector(const MyIntVector& v);
	~MyIntVector();

	void pop_back();
	// precondition : 0 < used
	// postcondition : �迭�� ���� ������ ��� ����
	void push_back(int x);
	// precondition : x is integer
	// postcondition : x�� �迭�� ���� ������ ��ҷ� �߰�
	size_t capacity() const { return space; };
	// precondition :
	// postcondition : �迭�� capacity(space) ��ȯ
	size_t size() const { return used; };
	// precondition :
	// postcondition : �迭�� size(used) ��ȯ
	void reserve(size_t n);
	// precondition : 0 <= n
	// postcondition : space ���� n���� ����
	bool is_empty() const;
	// precondition : 
	// postcondition : �迭�� ��������� true, �ƴҰ�� false ��ȯ
	void clear();
	// precondition :
	// postcondition : �迭�� ��� ��� ����

	void operator =(const MyIntVector& source);
	// precondition :
	// postcondition : ���׿� ���� ���� �Ҵ�
	void operator +=(const MyIntVector& addend);
	// precondition :
	// postcondition : ������ �迭 ���� ������ �迭�� �߰���
	int operator [](int n);
	// precondition : n < used && 0 <= n
	// postcondition : �迭�� n��° ��� ��ȯ
	MyIntVector operator + (const MyIntVector& source);
	// precondition : ������ used == ������ used
	// postcondition : ���װ� ������ �迭�� ��ҵ��� �ε��� ���� 
	//				   ���ؼ� ������ MyIntVector ��ȯ
	MyIntVector operator - (const MyIntVector& source);
	//precondition : ������ used == ������ used
	// postcondition : ���װ� ������ �迭�� ��ҵ��� �ε��� ���� 
	//				   ���� ������ MyIntVector ��ȯ
	int operator * (const MyIntVector& source);
	// precondition : ������ used == ������ used
	// postcondition : ���װ� ������ �迭�� ��ҵ��� ������ �� ��ȯ
	MyIntVector operator - ();
	// precondition :
	// postcondition : �迭�� �� ��ҵ鿡 * -1�� ��
	bool operator == (const MyIntVector& source);
	// precondition : 
	// postcondition : ���װ� ������ �迭�� ��ҵ��� ���ٸ� true ��ȯ,
	//				   �ƴ� �� false ��ȯ
	MyIntVector operator () (int n);
	// precondition :
	// postcondition : �迭�� size ��ŭ n������ ä��

private:
	int* data;
	size_t used;
	size_t space;
};