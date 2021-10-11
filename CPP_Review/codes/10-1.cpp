/*
	
	10-1 : C++ 표준 템플릿 라이브러리 (Standard Template Library - STL)

	3대장 : 
		1. container : vector, list, deque...
		2. iterator
		3. algorithm


	상수 반복자 :
		std::vector<int>::const_iterator citr = vec.cbegin() + 1;
		상수 반복자는 그 위치를 바꿀 수 없다!		
	
	iterator - 역반복자를 사용하는 것은 매우 중요하다!
		전통적인 방식으로 index를 이용하면, i가 0일때 i--를 해버리면 -1이 아니라
		MAX_INT값이 나오기 때문! (i가 unsigned int 타입이기 때문이다)

*/

#include <iostream>
#include <vector>
#include <list>

template <typename T>
void print_vector(std::vector<T>& vec) {
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
		itr++) {
		std::cout << *itr << std::endl;
	}
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
	for (const auto& elem : vec) {
		std::cout << elem << std::endl;
	}
}

template <typename T>
void print_list(std::list<T>& lis) {
	for (const auto& elem : lis) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

template <typename T>
class myDeque {


}


int main() {

	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
		std::cout << *itr << std::endl;
	}

	std::vector<int>::iterator itr = vec.begin() + 2;
	std::cout << "3 번째 원소 :: " << *itr << std::endl;

	print_vector(vec);

	std::vector<int>::const_iterator citr = vec.cbegin() + 2;

	std::vector<int>::reverse_iterator r_iter = vec.rbegin();
	for (; r_iter != vec.rend(); r_iter++) {
		std::cout << *r_iter << std::endl;
	}
}