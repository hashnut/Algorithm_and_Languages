/*
 *	new와 malloc은 어떻게 다를까? : new는 객체를 동적으로 생성하면서
 *	동시에 자동으로 생성자도 호출해준다! -> C++에 맞는 새로운 동적할당!
 *
 *	클래스 내부에 동적으로 할당한 것이 있다면 반드시 소멸자를 통해
 *	메모리를 해제해 주어야 한다 -> Memory Leak 방지!
 *
 *	같은 클래스의 같은 내용의 인스턴스를 계속 호출할 때는?
 *	: 복사 생성자(copy constructor) 가 유용하게 쓰일 수 있다.
 *
 *		"T(const T& a)"
 *		T의 객체 a를 상수 레퍼런스로 받아 '복사'만을 수행한다!
 *
 *		some_class a = b;
 *		
 *		이것은 마치
 *		
 *		some_class a(b); 처럼 작동하여 복사 생성자를 자동으로 호출한다!
 *
 *		C++에서는 복사 생성자를 만들지 않더라도 default로 해당 기능이 존재한다
 *
 *		
 *		하지만 한 가지 문제가 있는데, 만약 b가 a의 이름 (char*)을 복사했다고 하자.
 *		default copy constructor는 '얕은 복사'(그냥 같은 주소를 가리키게 함)
 *		를 하므로, a를 b에 복사한 후, a를 delete하면, b가 가리키는 곳이 사라져 버린다.
 *		이는 런타임 에러를 발생시키므로, 이 경우에는 새로운 복사 생성자를 만들어
 *		이를 해결해야 한다 (동적할당을 해 주기)
 *
 *		
 *
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Test
{

	char c;
	char* name;

public:
	Test(char _c)
	{
		c = _c;
		cout << "생성자 호출 " << c << endl;
	}

	Test(char _c, char* _name)
	{
		c = _c;
		name = _name;
	}

	~Test() { cout << "소멸자 호출 " << c << endl; if (name != NULL) delete[] name;}

};

void simple_function() { Test b('b'); }


class string2 {
  char *str;
  int len;

 public:
  string2(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  string2(const char *s);
  string2(const string2 &s);
  ~string2();

  void add_string(const string2 &s);   // str 뒤에 s 를 붙인다.
  void copy_string(const string2 &s);  // str 에 s 를 복사한다.
  int strlen() const {return len;}				// 문자열 길이 리턴
};

void string2::add_string(const string2 &s)
{
	if (str) delete[] str;

	char* original = new char[len+1];
	strcpy(original, str);
	len += s.strlen();
	str = new char[len + 1];
	strcpy(str, original);

	*str += len;
	char* temp = s.str;
	while (*temp)
	{
		*str++ = *temp++;
	}
}

void string2::copy_string(const string2 &s)
{
	if (str) delete[] str;

	len = s.strlen();
	str = new char[len+1];

	char* temp = s.str;
	while(*temp)
	{
		*str++ = *temp++;
	}

}


int main()
{
	Test a('a');
	simple_function(); // a b b a

}
