/*
 *	함수 오버로딩의 과정은 다음과 같다
 *
 *	1. 자신과 타입이 정확히 일치하는 함수를 찾는다
 *	2. 정확히 일치하는 타입이 없을 경우, 형변환을 통해서 일치하는 함수를 찾아본다
 *		
 *		Char, unsinged char, short -> int
 *		unsinged short 는 int의 크기에 따라 int 혹은 unsigned int로 변환
 *		float은 double로변환
 *		enum은 int로 변환
 *
 *	3. 위와 같이 변환해도 일치하는 것이 없으면 좀더 포괄적인 형 변환을 진행함
 *		
 *		numeric type은다른 숫자 타입으로 변환 (float -> int)
 *		enum도 임의의 숫자 타입으로 변환 (enum -> double)
 *		0은 포인터 타입이나 숫자 타입으로 변환된 0은 포인터 타입이나 숫자 타입으로 변환
 *		포인터는 void 포인터로 변환
 *
 *  4. 유저 정의된 타입 변환으로 일치하는 것을 찾는다.
 *		
 *		만약 컴파일러가 위 과정을 거쳐도 일치하는 함수를 못 찾거나,
 *		두 개 이상이 일치하는 경우에 모호하다(ambiguous)라고 판단해 오류를 리턴
 *
 *
 */


#include <iostream>
#include <stdlib.h>

using namespace std;

class Date()
{
	int day_;
	int month_;
	int year_;

public: 
	Date()
	{
		year = 2012;
		month = 1;
		day = 12;
	}

	// It means to define default constructor
	Date() = default;

}


class Point
{
private:
	int x, y;

public:
		Point(int pos_x, int pos_y);

};

class Geometry
{
public:
	Geometry()
	{
		num_points = 0;
	}

	void AddPoint(const Point &point)
	{
		point_array[num_points++] = new Point(point.x, point.y);
	}

	// 모든 점들 간의 거리를 출력하는 함수
	void printDistance();
	// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수
	void PrintNumMeets();


}




void print(int x) {cout << x << endl;}
void print(char x) {cout << x << endl;}

int main()
{
	double c = 3.2f;

	// Ambiguous error! (double can be converted to "int" and "char" in STEP 3)
	// print(c);

	// Various ways to make Date instance
	Date day;
	Date day2 = Date();
	
	// It means to make a function with no argument returning Date type 
	Date day3_func();
	


}
