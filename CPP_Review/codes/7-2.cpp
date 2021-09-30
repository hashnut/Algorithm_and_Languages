/*

	7-2 : C++ 에서 파일 입출력 : ifstream, ofstream, stringstream


*/

#include <fstream>
#include <iostream>
#include <string>

class Human {
	std::string name;
	int age;

	public:
	Human(const std::string& name, int age) : name(name), age(age) {}
	std::string get_info() {
		return "Name :: " + name + " / Age :: " + std::to_string(age);
	}
	friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream& o, Human& h) {
	o << h.get_info();
	return o;
}

int main() {
	std::ifstream in("test.txt");
	std::string s;

	if (in.is_open()) {
		in >> s;
		std::cout << "입력 받은 문자열 :: " << s << std::endl;
	} else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}

	// 만일 하나의 파일만 읽는다면 닫을 필요없음 (ifstream이 자동으로 소멸자 호출)
	in.close();

	// binary 옵션을 주면 binary형태로 이진 데이터를 받는다.
	// binary는 단순한 숫자로 ios에 정의되어 있고, OR을 해서 옵션을 조합할 수 있다!
	in.open("other.txt", std::ios::binary);

	int x;
	if (in.is_open()) {
		in.read((char*)(&x), 4);
		// hex는 16진수로 정수 데이터를 표시해준다
		std::cout << std::hex << x << std::endl;
	} else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}


	// 파일 전체 한 번에 읽기
	in.close();
	in.open("test.txt");

	if (in.is_open()) {
		// 위치 지정자를 파일 끝으로 옮긴다
		in.seekg(0, std::ios::end);

		// 그리고 그 위치를 읽는다 (파일의 크기)
		int size = in.tellg();

		// 그 크기의 문자열을 할당한다.
		s.resize(size);

		// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
		in.seekg(0, std::ios::beg);

		// 파일 전체 내용을 읽어서 문자열에 저장한다.
		in.read(&s[0], size);
		std::cout << s << std::endl;
	} else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}

	in.close();
	in.open("other.txt");

	char buf[100];

	if (!in.is_open()) {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
		return 0;
	}

	// CASE 1 : ifstream의 operator bool()을 이용
	// in이 true이기 위해서는 다음 입력 작업이 성공적이어야만 하고, 현재 스트림에 오류 플래그가 켜져 있지 않아야만 함.
	// ifstream의 getline은 버퍼의 크기가 다 차면 failbit를 키는 한계가 있어 버퍼의 크기가 작으면 정상적으로 데이터를 받을 수 없음
	// while (in) {
	// 	// 세번째 인자에 문자를 주면 해당 글자가 나올 때까지 입력을 받는다.
	// 	in.getline(buf, 100, '.');
	// 	std::cout << buf << std::endl;
	// }

	// CASE 2 : std::string의 getline 함수 이용
	// 굳이 버퍼의 크기를 지정하지 않아도 알아서 개행 문자 혹은 파일에 끝이 나올 때까지 입력받게 된다.
	while (in) {
		getline(in, s);
		std::cout << s << std::endl;
	}

	// !!! while문 조건으로 절대 in.eof()를 사용하면 안된다. (99프로 잘못된 코드)
	// 왜냐하면 eof함수는 파일 위치 지시자가 파일의 끝에 도달한 "이후"에 true를 리턴하기 때문!
	// 즉 한번 더 읽힐 수 있다! in >> data를 하면 data에 아무것도 들어가지 않음.


	// 파일에 쓰는 것도 비슷하게 진행된다.

	// app : 원본에 이어쓰기
	// ate : 원본 특정 위치부터 이어쓰기 (원본 보존 X)
	// trunc : 기존 내용을 지우기
	std::ofstream out("out.txt", std::ios::app);

	std::string s2;
	if (out.is_open()) {
		out << "덧붙이기";
	}



	return 0;
}
