/*

	10-2 : C++ STL - set, map, unordered_set, unordered_map

	set : 집합을 표현 (multiset)
	map : 해당 키가 있다면 대응되는 값은 무엇인가요? (multimap)

	set은 내부적으로 트리 구조로 구성되어 있다!

	multiset : allow to add duplicated keys
	mutlmap : allow to add duplicated key-value pairs

		When using map, it is not desirable to use [] operator to find values
		map_list["Key Doesn't exist"] -> it makes a new key-value pair, with value 0
		instead, use "find" function to find corresponding value

		insert : add new key-value pair (but if the key exist, it is ignored)
		[] : add new key-value pair (if the key exist, it updates its value)

	
	unordered_set / unordered_map :
		elementes are added randomly, not in sorted order.
		BUT, insert, erase, find are all O(1) - use hash table
		Worst Case : O(N)


	Summary : 

		데이터의 존재 유무 만 궁금할 경우 → set

		중복 데이터를 허락할 경우 → multiset (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

		데이터에 대응되는 데이터를 저장하고 싶은 경우 → map

		중복 키를 허락할 경우 → multimap (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))

	

*/

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <functional>

template <typename T, typename C>
void print_set(std::set<T, C>& s) {
	for (const auto& elem : s) {
		std::cout << elem << " " << std::endl;
	}
}

class Todo {
	int priority;
	std::string job_desc;

public:
	Todo(int priority, std::string job_desc)
	: priority(priority), job_desc(job_desc) {}

	bool operator<(const Todo& t) const {
		if (priority == t.priority) {
			return job_desc < t.job_desc;
		}
		return priority > t.priority;
	}

	bool operator==(const Todo& t) const {
		if (priority == t.priority && job_desc == t.job_desc) return true;
		else return false;
	}

	
	friend struct std::hash<Todo>;
	friend std::ostream& operator<<(std::ostream& o, const Todo& td);

	/*
	// 만약 이렇게 만들면, priority 값이 같은 원소가 추가되지 않는다!
	bool operator<(const Todo& t) const {
		return priority > t.priority;
	}
	// 따라서, operator< 안에서 다른 객체들이 구분될 수 있도록 만들어야 한다!

	*/
};

/*
struct TodoCmp {
	bool operator()(const Todo& a, const Todo& b) const {
		if (a.priority == b.priority) {
			return a.job_desc < b.job_desc;
		}
		else return a.priority > b.priority;
	}
};
*/

std::ostream& operator<<(std::ostream& o, const Todo& td) {
	o << "[ 중요도 : " << td.priority << "] " << td.job_desc;
	return o;
}

template <typename K, typename V>
void print_map(std::map<K, V> &m) {
	for (const auto& elem : m) {
		std::cout << elem.first << " " << elem.second << std::endl;
	}
}

namespace std {

template <>
struct hash<Todo> {
	size_t operator()(const Todo& t) const {
		hash<string> hash_func;
		return t.priority ^ (hash_func(t.job_desc));
	}
};

} // namespace std


int main() {

/*
	std::set<Todo, TodoCmp> todos;


	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));

	print_set(todos);

	std::cout << "---------------" << std::endl;
	std::cout << "숙제를 끝냈다면!" << std::endl;
	todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
	print_set(todos);
*/

	std::map<std::string, double> pitcher_list;

	// 참고로 2017년 7월 4일 현재 투수 방어율 순위입니다.

	// 맵의 insert 함수는 pair 객체를 인자로 받습니다.
	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
	pitcher_list.insert(std::pair<std::string, double>("해커 ", 2.93));

	pitcher_list.insert(std::pair<std::string, double>("피어밴드 ", 2.95));

	// 타입을 지정하지 않아도 간단히 std::make_pair 함수로
	// std::pair 객체를 만들 수 도 있습니다.
	pitcher_list.insert(std::make_pair("차우찬", 3.04));
	pitcher_list.insert(std::make_pair("장원준 ", 3.05));
	pitcher_list.insert(std::make_pair("헥터 ", 3.09));

	// 혹은 insert 를 안쓰더라도 [] 로 바로
	// 원소를 추가할 수 있습니다.
	pitcher_list["니퍼트"] = 3.56;
	pitcher_list["박종훈"] = 3.76;
	pitcher_list["켈리"] = 3.90;

	print_map(pitcher_list);

	std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;

	// It is allowed to add same keys
	std::multimap<int, std::string> m;
	m.insert(std::make_pair(1, "hello"));
	m.insert(std::make_pair(1, "hi"));

	// You shouldn't use s[1], since it doesn't know which value you want to get
	// print out all values whose key is 1 / range.first - begin, range.second - end
	auto range = m.equal_range(1);
	for (auto itr = range.first; itr != range.second; itr++) {
		std::cout << itr->first << " : " << itr->second << " " << std::endl;
	}











}
 