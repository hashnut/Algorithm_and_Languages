/*

	5-3 : 연산자 오버로딩 프로젝트 - N 차원 배열

	C++ 스타일의 캐스팅 : 암시적 / 명시적
		1. static_cast : 언어적 차원에서 지원하는 일반적인 타입 변환
		2. const_cast : 객체의 상수성(const)를 없애는 타입 변환. 쉽게 말해 const int가 int로 바뀐다.
		3. dynamic_cast : 파생 클래스 사이에서의 다운 캐스팅
		4. reinterpret_cast : 위험을 감수하고 하는 캐스팅으로 서로 관련이 없는 포인터들 사이의 캐스팅 등

		ex) static_cast<int>(float_variable); // 이는 (int)(float_variable)과 같다.


*/

#include <iostream>

class Array {
	const int dim;
	int* size; // size[0] * size[1] * ... * size[dim-1] 짜리 배열이다.

	struct Address {
		int level;
		// 맨 마지막 레벨(dim - 1 레벨)은 데이터 배열을 가리키고,
		// 그 위 상위 레벨에서는 다음 Address 배열을 가리킨다.
		void* next;
	};
	Address* top;

public:
	Array(int dim, int* array_size) : dim(dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = array_size[i];
		
		top = new Address;
		top->level = 0;

		initialize_address(top);
	}

	Array(const Array& arr) : dim(arr.dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = arr.size[i];

		top = new Address;
		top->level = 0;

		initialize_address(top);

		copy_address(top, arr.top);
	}

	// address를 초기화 하는 함수이다. 재귀호출로 구현
	void initialize_address(Address* current) {
		if (!current) return;
		if (current->level == dim - 1) {
			current->next = new int[size[current->level]];
			return;
		}

		current->next = new Address[size[current->level]];
		for (int i = 0; i != size[current->level]; i++) {
			(static_cast<Address*>(current->next) + i)->level = current->level + 1;
			
			initialize_address(static_cast<Address*>(current->next) + i);
		}
	}

	void delete_address(Address* current) {
		if (!current) return;
		for (int i = 0; current->level < dim-1 && i < size[current->level]; i++) {
			(static_cast<Address*>(current->next) + i)->level = current->level + 1;
		}
		if (current->level == dim - 1) {
			delete[] static_cast<int*>(current->next);
		}
		delete[] static_cast<Address*>(current->next);
	}

	void copy_address(Address* dst, Address* src) {
		if (dst->level == dim - 1) {
			for (int i = 0; i < size[dst->level]; i++) {
				static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
			}
			return;
		}
		for (int i = 0; i != size[dst->level]; i++) {
			Address* new_dst = static_cast<Address*>(dst->next) + i;
			Address* new_src = static_cast<Address*>(src->next) + i;
			copy_address(new_dst, new_src);
		}
	}


	~Array() {
		delete_address(top);
		delete[] size;
	}
};

int main() {

}
