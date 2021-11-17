/*

  5-1 : 연산자 오버로딩
  
  연산자 함수의 리턴 타입에 유의하자. 리턴 타입을 참조 타입 (아래의 예시에서는 Complex&로 주게 되면)
  속도의 저하는 나타나지 않지만, a = b + c + b; 의 경우, b의 값이 바뀌어 원하는 결과가 나오지 않게 된다.
  
  operator=을 구현할 때는, 리턴 타입을 참조형으로 리턴한다. 그래야만 a = b = c; 에서 원하는 결과가 나오게 된다.
  하지만 operator=은 따로 구현하지 않더라도 디폴트 복사 생성자가 호출될 수 있는데, 얕은 복사가 수행되므로,
  클래스 내부적으로 동적으로 할당된 메모리를 관리하는 포인터가 있다면 대입 연산자 함수를 꼭 만들어 주어야 한다.

  1. Some_Class a = b; // 복사 생성자 호출
  2. Some_Class a; a = b; // 기본 생성자 호출 후, 대입 연산자 함수 실행

  컴파일러는 +와 =를 정의했다고 해서 += 를 자동으로 호출하지 않는다!
  
  Complex(const char* str); 와 같은 생성자를 만들어 주면,
  Complex a = Complex(1, 2);
  a = a + "1 + i21";
  를 호출했을 때, 뒷부분의 string literal이 자동으로 Complex 클래스로 형 변환이 된다!
  
  다만 한 가지 짚고 넘어가야 할 점은, operator+ 에서 `const Complex& c` 가 아닌 `Complex& c`를 쓰면 안된다는 것이다!
  string literal 자체를 const로 인식하므로, string literal을 통해 생성된 객체도 const이어야 하기 때문이다.

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

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    Complex& operator=(const Complex& c);

    void println() {
        std::cout << "( " << real << " , " << img << " ) " << std::endl;
    }
};
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
        }
        else if (str[i] == '.')
            integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        }
        else
            break;  // 그 이외의 이상한 문자들이 올 경우
    }

    if (minus) num *= -1.0;

    return num;
}

double Complex::get_number(const char* str, int from, int to) const {
    
    double n = 0.0;

    char* buf = new char[to-from+2];
    memcpy(buf, &str[from], to - from + 1);
    buf[to-from+1] = '\0';

    n = atof(buf);

    return n;
}
Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) const {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) const {
    Complex temp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

int main() {
    Complex a(0, 0);
    a = a + "-1.1 + i3.923";
    a.println();
    a = a - "1.2 -i1.823";
    a.println();
    a = a * "2.3+i22";
    a.println();
    a = a / "-12+i55";
    a.println();
}
