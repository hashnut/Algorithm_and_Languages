/*

	12-1 : 우측값 레퍼런스와 이동 생성자

	예시 :
		int a = 3;
		1. 좌측값(lvalue) : a는 주소값을 취할 수 있으므로 lvalue이다
		2. 우측값(rvalue) : 3은 주소값을 취할 수 없으므로 rvalue이다


	레퍼런스는 좌측값에만 취할 수 있다.
		int a;
		int& l_a = a; // 좌측값 레퍼런스
		int& r_b = 3; // 3은 우측값이므로 오류이다.


	이동생성자는 우측값을 &&를 통해 마치 좌측값인 것처럼 사용할 수 있게 해준다.
		이때, str.string_content = nullptr;
		처럼 소멸되지 않도록 붙잡고 있어야 한다.


	주의점 : vector에 이러한 element를 넣을 때는 이동생성자를 반드시 noexcept로 명시해야 한다.
		vector에 새로운 원소를 추가할 때, 할당해놓은 메모리가 부족하면?
		-> 새로운 메모리를 할당한 후에, 기존에 있던 원소들을 새로운 메모리로 옮기게 된다.

		하지만 만약 이동 생성하는 과정에서 예외가 발생한다면, 기존의 메모리에 원소들이 모두
		이동되어 사라져버렸기 때문에, 새로 할당한 메모리를 섣불리 해제해버릴 수 없다!
		따라서 vector는 이동 생성자가 noexcept가 아닌 이상 이동 생성자를 사용하지 않는다.

*/

#include <iostream>

class MyString {

};

MyString::MyString(MyString&& str) noexcept {
	std::cout << "이동 생성자 호출 !" << std::endl;
	string_length = str.string_length;
	string_content = str.string_content;
	memory_capacity = str.memory_capacity;

	str.string_content = nullptr;
}

int main() {

	int a;
	int& l_a = a;
	int& ll_a= 3; // 불가능

	int&& r_b = 3;
	int&& rr_b = a; // 불가능. 우측값 레퍼런스의 경우 반드시 우측값의 레퍼런스만 가능하다.


}
