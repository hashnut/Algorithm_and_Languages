/*

	10-3 : STL - algorithm

	General built-in functions of algorithm :
		typename <typename Iter>
		void do_something(Iter begin, Iter end);

		typename <typename Iter, typename Pred>
		void do_something(Iter begin, Iter end, Pred pred);	

	
	SORTING : 
		1. sort
		2. stable_sort
		3. partial_sort


	vector erase grammar : 
		vec.erase(std::remove(vec.begin(), vec.end(), T_something), vec.end());
	//remove -> move iterator point to the end
	//erase -> reposition iterator end point


	Lambda function :
		[capture list] (받는 인자) -> 리턴 타입 { 함수 본체 }
		capture list 에 무엇을 넣는지에 따라 사용방법이 달라진다!
		[] : 아무것도 캡쳐 안함
		[&a, b] : a는 레퍼런스로 캡쳐하고 b는 (const) 복사본으로 캡쳐
		[&] : 외부의 모든 변수들을 레퍼런스로 캡쳐
		[=] : 외부의 모든 변수들을 복사본으로 캡쳐


	원소 수정하기 (transform)

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>


template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}

struct User {
	std::string name;
	int age;

	User(std::string name, int age) : name(name), age(age) {}
	bool operator<(const User& u) const { return age < u.age; }
};

std::ostream& operator<<(std::ostream& o, const User& u) {
	o << u.name << " , " << u.age;
	return o;
}

struct int_compare {
	bool operator()(const int& a, const int& b) const { return a > b; }
};

struct is_odd {

	int* num_delete;

	is_odd(int* num_delete) : num_delete(num_delete) {}

	bool operator()(const int& i) {
		if (*num_delete >= 2) return false;

		if (i % 2 == 1) {
			*num_delete++;
			return true;
		}	

		return false;
	}
};	

class SomeClass {
	std::vector<int> vec;

	int num_erased;

public:
	SomeClass() {
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	num_erased = 0;

	vec.erase(std::remove_if(vec.begin(), vec.end(),
	                         [this](int i) {
	                           if (this->num_erased >= 2)
	                             return false;
	                           else if (i % 2 == 1) {
	                             this->num_erased++;
	                             return true;
	                           }
	                           return false;
	                         }),
	          vec.end());
	}
};


int main() {

	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(2);

	std::cout << "----" << std::endl;
	print(vec.begin(), vec.end());
	std::sort(vec.begin(), vec.end(), int_compare());

	std::cout << "----" << std::endl;
	print(vec.begin(), vec.end());
	
	vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());	

	int num_delete = 0;
	//vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd(&num_delete)), vec.end());
	//vec.erase(std::remove_if(vec.begin(), vec.end(), [](int i) -> bool {return i % 2 == 1; }), vec.end());

	int num_erased = 0;
	vec.erase(std::remove_if(vec.begin(), vec.end(),
			[&num_erased](int i) {
				if (num_erased >= 2)
					return false;
				else if (i % 2 == 1) {
					num_erased++;
					return true;
				}
				return false;
			}), vec.end());

	print(vec.begin(), vec.end());
}
