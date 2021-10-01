/*

	7-1 : 입출력 스트림
	C++의 모든 입출력 클래스는 ios_base를 기반 클래스로 한다.

	ios_base : 스트림의 입출력 형식 관련 데이터 처리
	ios : 스트림 버퍼를 초기화, 입출력 작업의 상태 처리 (eof 등)
		-> 스트림의 상태를 관리하는 flag는 4개가 있다.
		1. goodbit : 스트림에 입출력 작업이 가능할 때
		2. badbit : 스트림에 복구 불가능한 오류 발생시
		3. eofbit : 스트림에 복구 가능한 오류 발생시
		4. failbit : 입력 작업시에 EOF 도달시

*/

#include <iostream>


using namespace std;
int main() {
	int t;

	while (true) {
		std::cin >> t;
		// 'c'를 입력했을 경우, 무한루프가 돈다...
		// failbit가 켜지고, 입력값을 받지 않고 리턴해버리기 때문! 
		std::cout << "입력 :: " << t << std::endl;
		if (t == 0) break;
	}

	while (std::cin >> t) {
		// 'c'를 입력했을 경우, 종료한다.
		std::cout << "입력 :: " << t << std::endl;
		if (t == 0) break;
	}

	while (true) {
		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "제대로 입력해주세요" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		if (t == 1) break;
	}

	while (true) {
		// setf : 첫 인자는 형식 플래그 적용. 두번째 인자는 basefield의 내용을 초기화\
		// std::ios_base::hex는 단순한 상수 '값'이다.
		//std::cin.setf(std::ios_base::hex, std::ios_base::basefield);

		// hex는 조작자이다! (함수임)
		std::cin >> std::hex >> t;
		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if (std::cin.fail()) {
			// std::endl은 flush의 역할도 수행한다.
			std::cout << "제대로 입력해주세요" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		if (t == 0) break;
	}

	std::string s;
	std::cin >> s;

	// rdbuf()->snextc() 함수는 스트림 위치 지정자를 건드리지 않는다.
	char peek = std::cin.rdbuf()->snextc();
	if (std::cin.fail()) std:cout << "Failed";
	std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
	std::cin >> s;
	std::cout << "다시 읽으면 : " << s << std::endl;

}
