/*

  9-2 : 가변 길이 템플릿 (Variadic Template)

	가변 길이 템플릿을 이용하면 갯수가 지정되지 않은 인수들을 인자로 받을 수 있다.
	재귀함수 호출의 형태로 구성된다. -> 종료 조건 함수가 있어야 함
	C++ 17 이후로는 Fold 형태로 식을 구성할 수 있다.


*/

#include <iostream>
#include <string.h>

// 아래의 파라미터 팩 함수와 순서를 바꾸면 컴파일 에러가 난다!
template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
}



size_t GetStringSize(const char* s) { return strlen(s); }
size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
	return GetStringSize(s) + GetStringSize(strs...);
}


void AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs) {
	concat_str->append(s);
	AppendToString(concat_str, strs...);
}

template <typename String>
std::string StrCat(const String& s) {
	return std::string(s);
}

template <typename String, typename...Strings>
std::string StrCat(const String& s, Strings... strs) {

	size_t total_size = GetStringSize(s, strs...);

	std::string concat_str;
	concat_str.reserve(total_size);

	concat_str = s;

	AppendToString(&concat_str, strs...);


	return concat_str;
}

// 가변 길이 템플릿은 재귀 함수 형태로 구성하므로, 재귀 호출 종료를 위한 함수를 따로 만들었어야 했다.
// C++ 17부터는 Fold로 간단히 표현할 수 있다.
int sum_all() { return 0; }

template <typename... Ints>
int sum_all(int num, Ints... nums) {
	return num + sum_all(nums...);
}

template <typename... Ints>
int sum_all_fold(Ints... nums) {
	return (... + nums); // return ((((1 + 4) + 2) + 3) + 10); 이런 식으로 해석된다! (Unary left fold)
	// 단, Fold 식을 쓸 때는 꼭 ()로 감싸줘야 한다.
}

template <typename... Ints>
double average(Ints... nums) {
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

template <typename Int, typename... Ints>
Int diff_from(Int start, Ints... nums) {
	return (start - ... - nums);
}

class A {
public:
	void do_something(int x) const {
		std::cout << "Do something with " << x << std::endl;
	}
};

// 가변 길이 템플릿을 사용하면, ','로 마치 for loop을 돌린 것 같은 효과를 낼 수 있다.
template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums) {
	(t.do_something(nums), ...);
}

int main() {
	print(1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);

	std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"), " ", std::string("sentence")) << std::endl;

	std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;

	A a;
	do_many_things(a, 1, 3, 2, 4);

}
