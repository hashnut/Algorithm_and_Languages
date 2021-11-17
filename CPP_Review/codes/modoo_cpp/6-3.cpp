/*

	6-3 : 가상함수와 상속에 관련한 잡다한 내용들

	소멸자 호출시, 다음과 같은 식으로 쓰게되면...
	Parent *p = new Child();
	delete p;
	
	Parent 생성자 호출
	Child 생성자 호출
	Parent 소멸자 호출

	이 되어 memory leak이 발생한다.

	즉, 이 경우, Parent의 생성자 앞에 virtual을 붙여주어
	delete p; 가 실행될때 Child의 소멸자가 올바르게 호출되도록 만들어야 한다!


	
	그렇다면 왜 모든 함수들을 virtual로 선언하지 않을까? (자바처럼)
	-> 약간의 오버헤드가 필요하기 때문에 이를 피한다!
	-> 예시인 Parent, Child 클래스 참고

	컴파일러는 가상 함수가 하나라도 존재하는 클래스에 대해 가상 함수 테이블(Virtual function table; vtable)을 만든다.
	따라서 가상 함수를 호출할 때에는 vtable에서 해당 함수를 확인하는 과정을
	한 단계 더 거치므로, 약간의 오버헤드가 필요하다.
	
	

	순수 가상함수 : 
	
	virtual void speak() = 0;
	같은 꼴의 함수는, 반드시 오버라이딩 되도록 만든 함수이다.
	순수 가상 함수는 본체가 없고, 이를 구현한 객체를 생성하는 것도 불가능하다.
	순수 가상 함수를 하나라도 포함한 클래스를 Abstract Class라고 한다.
	추상 클래스를 가리키는 포인터는 사용 가능하다.



	다중 상속 : 
	C++에서는 다중상속을 지원한다.
	class C : public B, public A {};
	이때, 생성자 호출 순서는 B->A->C 순이다.



	다이아몬드 상속 :
	상속이 되는 두 개의 클래스가 공통의 베이스 클래스를 포함하는 형태
	부모들이 같은 멤버 변수를 가지는 경우, 다중 상속 시 어떤 부모 클래스의 변수인지 알 수 없다.
	(예시는 Human을 참고)
	겹치는 부모 클래스를 virtual로 상속받는다면, 다중 상속시 컴파일러가
	해당 부모 클래스를 한 번만 포함하도록 지정할 수 있다.
*/

#include <iostream>

class Parent {
public:
	virtual void func1();
	virtual void func2();
};

class Child : public Parent {
public:
	virtual void func1();
	void func3();
};

class Human {};
class HandsomeHuman : public virtual Human {};
class SmartHuman : public virtual Human {};
class Me : public HandsomeHuman, public SmartHuman {};
