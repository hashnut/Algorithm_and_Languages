/*

	11-1 : C++ 에서 예외 처리

	예외 발생시키기 - throw

	
	스택 풀기 (Stack unwinding)
		catch로 점프하면서 스택 상에서 정의된 객체들을 소멸시키는 과정
	
	
	noexcept : 이 키워드가 붙은 함수는 예외를 발생시키지 않는다고 생각하고 컴파일됨

	int foo() noexcept { throw 1; }
	-> 이 경우, 컴파일은 되지만 예외가 발생한다면 예외가 제대로 처리되지 않고 프로그램이 종료됨


*/

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Vector {
public:
	Vector(size_t size) : size_(size) {
		data_ = new T[size_];
		for (int i = 0; i < size_; i++) {
			data_[i] = 3;
		}
	}

	const T& at(size_t index) const {
		if (index >= size_) {
			throw std::out_of_range("vector 의 index 가 범위를 초과하였습니다.");
		}
		return data_[index];
	}
	~Vector() { delete[] data_; }

private:
	T* data_;
	size_t size_;
};


class Parent : public std::exception {
public:
	virtual const char* what() const noexcept override { return "Parent!\n"; }
};

class Child : public Parent {
public:
	const char* what() const noexcept override { return "Child!\n"; }
};

int func(int c) {
	if (c == 1) {
		throw Parent();
	} else if (c == 2) {
		throw Child();
	}
	return 0;
}


int func_all(int c) {
	if (c == 1) {
		throw 1;
	} else if (c == 2) {
		throw "hi";
	} else if (c == 3) {
		throw std::runtime_error("error");
	}
	return 0;
}


int main() {

	Vector<int> vec(3);

	int index, data = 0;
	std::cin >> index;

	try {
		data = vec.at(index);
	} catch (std::out_of_range& e) {
		std::cout << "예외 발생 ! " << e.what() << std::endl;
	}

	std::cout << "읽은 데이터 : " << data << std::endl;


	int c;
	std::cin >> c;

	// parent를 뒤에서 catch하도록 만들어 주어야 한다!
	// catch는 가장 먼저 대입될 수 있는 객체를 받는다 : Parent& p = Child();
	try {
		func(c);
	} catch (Child& c) {
		std::cout << "Child Catch!" << std::endl;
		std::cout << c.what();
	} catch (Parent& p) {
		std::cout << "Parent Catch!" << std::endl;
		std::cout << p.what();
	} 

	try {
		func_all(c);
	} catch (int e) {
		std::cout << "Catch int : " << e << std::endl;
	} catch (...) {
		std::cout << "Default Catch!" << std::endl;
	}

}