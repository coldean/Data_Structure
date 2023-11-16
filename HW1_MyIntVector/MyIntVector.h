//2019203102 유지성

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
	// postcondition : 배열의 가장 마지막 요소 제거
	void push_back(int x);
	// precondition : x is integer
	// postcondition : x를 배열의 가장 마지막 요소로 추가
	size_t capacity() const { return space; };
	// precondition :
	// postcondition : 배열의 capacity(space) 반환
	size_t size() const { return used; };
	// precondition :
	// postcondition : 배열의 size(used) 반환
	void reserve(size_t n);
	// precondition : 0 <= n
	// postcondition : space 값을 n으로 변경
	bool is_empty() const;
	// precondition : 
	// postcondition : 배열이 비어있으면 true, 아닐경우 false 반환
	void clear();
	// precondition :
	// postcondition : 배열의 모든 요소 삭제

	void operator =(const MyIntVector& source);
	// precondition :
	// postcondition : 좌항에 우항 값을 할당
	void operator +=(const MyIntVector& addend);
	// precondition :
	// postcondition : 좌항의 배열 끝에 우항의 배열을 추가함
	int operator [](int n);
	// precondition : n < used && 0 <= n
	// postcondition : 배열의 n번째 요소 반환
	MyIntVector operator + (const MyIntVector& source);
	// precondition : 좌항의 used == 우항의 used
	// postcondition : 좌항과 우항의 배열의 요소들을 인덱스 별로 
	//				   더해서 저장한 MyIntVector 반환
	MyIntVector operator - (const MyIntVector& source);
	//precondition : 좌항의 used == 우항의 used
	// postcondition : 좌항과 우항의 배열의 요소들을 인덱스 별로 
	//				   빼서 저장한 MyIntVector 반환
	int operator * (const MyIntVector& source);
	// precondition : 좌항의 used == 우항의 used
	// postcondition : 좌항과 우항의 배열의 요소들을 내적한 값 반환
	MyIntVector operator - ();
	// precondition :
	// postcondition : 배열의 각 요소들에 * -1을 함
	bool operator == (const MyIntVector& source);
	// precondition : 
	// postcondition : 좌항과 우항의 배열의 요소들이 같다면 true 반환,
	//				   아닐 시 false 반환
	MyIntVector operator () (int n);
	// precondition :
	// postcondition : 배열의 size 만큼 n값으로 채움

private:
	int* data;
	size_t used;
	size_t space;
};