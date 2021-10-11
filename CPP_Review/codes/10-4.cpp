/*

	10-4 : C++ 문자열의 모든 것 (string과 string_view)
	
	std::string 이란 무엇일까?
		사실 std::string 은 basic_string이라는 클래스 템플릿의 인스턴스화 버전이다.
		
		basic_string definition :
			
			template <class CharT, class Traits = std::char_traits<CharT>,
				class Allocator = std::allocator<CharT> >
			class basic_string;
		여기서, Traits를 바꾸면 정렬 순서를 바꿀 수 있는 등 여러가지 조작을 할 수 있다!


	짧은 문자열 최적화 (SSO)
		메모리 할당은 많은 시간을 잡아먹는다!
		basic_string은 짧은 길이 문자열의 경우 따로 문자 데이터를 위한 메모리를 할당하는 대신,
		그냥 객체 자체에 저장해버린다. -> Short String Optimization


*/


#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>

struct my_char_traits : public std::char_traits<char> {
	static int get_real_rank(char c) {
		if (isdigit(c)) {
			return c + 256;
		}
		return c;
	}

	static bool lt(char c1, char c2) {
		return get_real_rank(c1) < get_real_rank(c2);
	}

	static int compare(const char* s1, const char* s2, size_t n) {
		while (n-- != 0) {
			if (get_real_rank(*s1) < get_real_rank(*s2)) {
				return -1;
			}
			if (get_real_rank(*s1) > get_real_rank(*s2)) {
				return 1;
			}
			++s1;
			++s2;
		}
		return 0;
	}
};

// 이와 같이 new를 전역 함수로 정의하면 모든 new 연산자를 오버로딩해버린다.
// 어떤 클래스의 멤버 함수로 정의하면 해당 클래스의 new만 오버로딩됨
void* operator new(std::size_t count) {
	std::cout << count << " bytes 할당 " << std::endl;
	return malloc(count);
}


int main() {

	std::basic_string<char, my_char_traits> my_s1 = "1a";
	std::basic_string<char, my_char_traits> my_s2 = "a1";

	std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha
		<< (my_s1 < my_s2) << std::endl;

	std::string s1 = "1a";
	std::string s2 = "a1";

	std::cout << "일반 문자열 : " << std::boolalpha << (s1 < s2) << std::endl;

}