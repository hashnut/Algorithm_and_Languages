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
		transform (시작 반복자, 끝 반복자, 결과를 저장할 컨테이너의 시작 반복자, Pred)

	
	원소를 탐색하는 함수(find, find_if, any_of, all_of 등등)
		container에 자체 find 함수가 있다면 그걸 이용하자! (더 빠름)
		algorithm의 find함수는 타입을 모르므로, O(N)이다.	
		any_of : 인자로 받은 범위 안의 모든 원소들 중 조건을 하나라도 충족하면 true
		all_of : 모든 원소들이 전부 조건을 충족해야 true
	

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

struct Gamer {
	std::string name;
	int level;

	Gamer(std::string name, int level) : name(name), level(level) {}
	bool operator==(const Gamer& gamer) const {
		if (name == gamer.name && level == gamer.level) return true;
		return false;
	}
};

class Party {
	std::vector<Gamer> gamers;

public:
	bool add_gamer(std::string name, int level) {
		Gamer new_gamer(name, level);
		if (std::find(gamers.begin(), gamers.end(), new_gamer) != gamers.end()) {
			return false;
		}
		gamers.push_back(new_gamer);
		return true;
	}

	bool can_join_dungeon() {
		return std::all_of(gamers.begin(), gamers.end(),
			[](Gamer& gamer) { return gamer.level >= 15; });
	}

	bool can_use_special_item() {
		return std::any_of(gamers.begin(), gamers.end(),
			[](Gamer& gamer) { return gamer.level >= 19; });
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

	std::transform(vec.begin(), vec.end(), vec.begin(),
		[](int i) { return i + 1; });
	print(vec.begin(), vec.end());


	auto result = std::find(vec.begin(), vec.end(), 3);
	std::cout << "3 은 " << std::distance(vec.begin(), result) + 1 << " 번째 원소"
		<< std::endl;


	Party party;
	party.add_gamer("철수", 15);
	party.add_gamer("영희", 18);
	party.add_gamer("민수", 12);
	party.add_gamer("수빈", 19);

	std::cout << std::boolalpha;

}
