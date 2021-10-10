/*
	
	10-1 : C++ 표준 템플릿 라이브러리 (Standard Template Library - STL)

	3대장 : 
		1. container
		2. iterator
		3. algorithm

*/

#include <iostream>
#include <vector>

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
}