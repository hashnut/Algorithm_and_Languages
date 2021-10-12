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


	리터럴 연산자(literal operator)
		문자열 리터럴을 다음과 같이 정의해줄 수 있다.
		auto str = "hello"s;	 


	Raw String Literal : C++ 11에 추가된 문법
		std::string str = R"any(asdfasdf
		아무거나 아무거나
		))
		)any";

		같은 느낌으로... R을 붙이는게 포인트! any 대신에 어떤 단어가 와도 상관없다!


	C++에서 한글 다루기
		유니코드를 이용한다.
		UTF-8 : 문자를 최소 1부터 4바이트로 표현 (문자마다 길이가 다름)
		UTF-16 : 문자를 2 또는 4 바이트로 표현한다.
		UTF-32 : 문자를 4 바이트로 표현한다.

		// size() = 17. 각 문자열이 4바이트이다.
		std::u32string u32_str = U"이건 UTF-32 문자열 입니다"; 
		
		// size() = 32. 한글을 3바이트이고, 나머지는 1바이트. 총 32개의 char이 필요
		std::string str = u8"이건 UTF-8 문자열 입니다"; 

	UTF-16 인코딩
		최소 단위가 2바이트이다.
		대부분의 문자들이 2바이트로 인코딩 된다! (알파벳, 한글, 한자 전부)
		이모지나 상형문자 : 4바이트

		// size()  = 17
		std::u16string u16_str = u"이건 UTF-16 문자열 입니다";

	

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

// old version에서는, 문자열을 인자로 받을 때 객체를 생성하는 단점이 있었다!
bool contains_very_old(const std::string& str) {
	return str.find("very") != std::string::npos;
}

// string_view를 활용하면 소유하지 않고 읽기만 할 수 있다!
// 단 문자열을 소유하고 있지 않기 때문에, 현재 읽고 있는 문자열이 소멸되지 않은 상태인지 주의해야 함!
// 소멸된 것을 읽으면 Undefined behavior가 발생한다
bool contains_very(std::string_view str) {
	return str.find("very") != std::string_view::npos;
}


using namespace std::literals;

int main() {

	std::basic_string<char, my_char_traits> my_s1 = "1a";
	std::basic_string<char, my_char_traits> my_s2 = "a1";

	std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha
		<< (my_s1 < my_s2) << std::endl;

	std::string s1 = "1a";
	std::string s2 = "a1";

	std::cout << "일반 문자열 : " << std::boolalpha << (s1 < s2) << std::endl;

	auto hello = "hello"s;
	std::cout << "hello 길이 : " << hello.size() << std::endl;

	std::string str = R"any(asdfasdf
	아무거나 아무거나
	))
	)any";

	std::cout << str << std::endl;


	// UTF-8 에서 초성만 분리하기	
	std::u16string u16_str = u"안녕하세용 모두에 코드에 오신 것을 환영합니다";
	std::string jaum[] = {"ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ",
	                    "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ",
	                    "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"};

	for (char16_t c : u16_str) {
	// 유니코드 상에서 한글의 범위
	if (!(0xAC00 <= c && c <= 0xD7A3)) {
	  continue;
	}
	// 한글은 AC00 부터 시작해서 한 초성당 총 0x24C 개 씩 있다.
	int offset = c - 0xAC00;
	int jaum_offset = offset / 0x24C;
	std::cout << jaum[jaum_offset];
	}



}