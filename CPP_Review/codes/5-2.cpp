/*
  
  5-2 : 입출력, 첨자, 타입 변환, 증감 연산자
  
  **friend** : class 내부에서 다른 클래스나 함수들을 `friend`로 정의할 수 있다.
  friend로 선언된 클래스나 함수는 private으로 선언된 메소드와 변수를 가져다 쓸 수 있다!
  하지만 friend 관계는 일방향으로, A에서 B를 friend로 정의했다고 A가 B의 멤버 변수를 쓸 수 있는 것은 아니다.
  
  **이항연산자** : `a + "123"` 과  `"123" + a`는 같은 값이 나와야 한다!
  자기 자신을 리턴하는 이항연산자는 멤버 변수로, 아닌 애들은 외부 함수로 정의하자!
  
  **<<, >> 오버로딩** : 각각 ostream&과 &istream을 리턴 타입으로 설정하면 된다.
  
  **첨자 [] 오버로딩** : `char& operator[](const int index) { return string_content[index]; }`
  위와 같이 간단히 레퍼런스 주소만 리턴하면 된다!
  
  **Wrapper class와 연산자 구현** : 모든 연산에 대한 오버로딩 함수를 짤 필요없다.
  형 변환만 잘 해주면, 기본 타입의 연산자들을 잘 활용할 수 있다!
  `operator int() {return data;}` 같은 형식으로 표현하면 된다.
  
  **전위 연산자와 후위 연산자** : i++나 ++i같은 식을 쓰고 싶을때도, 연산자 오버로딩이 가능하다.
  전위 연산자(++i) : operator++();
  후위 연산자(i++) : operator++(int i); 혹은 operator++(int);
  다만 한 가지 주의해야 할 점은, 전위 연산자는 값이 바뀐 후의 객체를, 후위 연산자는 바뀌기 전의 객체를 리턴해야 한다는 것이다.
  
  전위 연산자 : opertor++() {a++; return *this;}
  후위 연산자 : opertor++(int) {A b = A(a); a++; return b;}
  
  후위 연산자는 객체를 리턴하기 전에 복사생성자를 호출해야 하므로, 전위 연산자에 비해 상대적으로 느리다.
  
  
  
*/

#include <iostream>
#include <cstring>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  Complex& operator+=(const Complex& c);
  Complex& operator=(const Complex& c);

  // 나머지 연산자 함수들은 생략 :)

  friend std::ostream& operator<<(std::ostream& os, const Complex& c);
  friend Complex operator+(const Complex& a, const Complex& b);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}

Complex operator+(const Complex& a, const Complex& b) {
  Complex temp(a.real + b.real, a.img + b.img);
  return temp;
}

Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}

Complex& Complex::operator+=(const Complex& c) {
  (*this) = *this + c;
  return *this;
}

Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

class Int {
	int data;
	
public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}

	operator int() { return data; }

};


int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;
  std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
}
