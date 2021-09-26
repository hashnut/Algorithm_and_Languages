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

}
