/*
    9-3 : 템플릿 메타 프로그래밍 (Template Meta programming)
    
    템플릿 메타 프로그래밍으로 작성된 코드는 모두 컴파일 타임에 모든 연산이 끝난다.
    즉, 프로그램 실행 속도를 향상시킬 수 있다는 장점이 있다(컴파일 타임은 늘어남)
*/

#include <iostream>
#include <typeinfo>
#include <string.h>
#include <math.h>


template <typename T, unsigned int N>
class Array {
    T data[N];

    public:

    Array(T (&arr)[N]) {
        for (int i = 0; i < N; i++) {
            data[i] = arr[i];
        }
    }

    T* get_array() { return data; }

    unsigned int size() { return N; }

    void print_all() {
        for (int i = 0; i < N; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }

};

template <int N>
struct Int {
    static const int num = N;
};

template <typename T, typename U>
struct add {
    typedef Int<T::num + U::num> result;
};

template <int N>
struct Factorial {
    static const int result = N * Factorial<N-1>::result;
};

template <>
struct Factorial<1> {
    static const int result = 1;
};


// 유클리드 호제법을 템플릿 메타 프로그래밍으로 표현해 보자
template <int M, int N>
struct gcd {
    static const int result = gcd<N, M % N>::result;
};

template<int M>
struct gcd<M, 0> {
    static const int result = M;
};

template <int N, int D = 1>
struct Ratio {
    typedef Ratio<N, D> type; // pointing itself -> similar to 'this' in class
    static const int num = N;
    static const int den = D;
};

template <class R1, class R2>
struct _Ratio_add {
    typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};


template<int N>
struct fib {
    static const int result = fib<N-1>::result + fib<N-2>::result;
};

template<>
struct fib<1> {
    static const int result = 1;
};

template<>
struct fib<2> {
    static const int result = 1;
};

template<int N, int M>
struct _is_prime {
    static const bool result = ((N % M) ? false : true) || _is_prime<N, M-1>::result;
};

template<int N>
struct _is_prime<N, 1> {
    static const bool result = false;
};

template<int N>
struct is_prime {
    static const bool result = !(_is_prime<N, static_cast<int>(sqrt(N))>::result); 
};

int main() {

    int arr[3] = {1, 2, 3};

    Array<int, 3> arr_w(arr);

    arr_w.print_all();

    std::cout << (typeid(Array<int, 3>) == typeid(Array<int, 5>)) << std::endl;


    // 컴파일 타임에 수행된다!
    typedef Int<1> one;
    typedef Int<2> two;

    typedef add<one, two>::result three;

    std::cout << "Addition result : " << three::num << std::endl;


    // 간단한 팩토리얼 예제
    std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;


    // 템플릿 메타 프로그래밍을 적용한 GCD
    std::cout << "gcd (36, 24) :: " << gcd<36, 24>::result << std::endl;



    // Ratio 이용하기
    typedef Ratio<2, 3> rat;
    typedef Ratio<3, 2> rat2;
    // You can use 'using' instead of 'typedef', which is more intuitive
    //typedef Ratio_add<rat, rat2> rat3;
    using rat3 = Ratio_add<rat, rat2>;

    std::cout << rat3::num << " / " << rat3::den << std::endl;


    // Following 2 lines are the same
    //typedef void (*func)(int, int);
    using func = void (*)(int, int);


    // Fibonacci TMP example
    std::cout << "5 번째 피보나치 수 :: " << fib<5>::result << std::endl; // 5



    // Prime Check TMP
    std::string boolalpha = "소수 판별 TMP";
    std::cout << boolalpha;
    std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl;   // true
    std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl;  // false

    std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl;  // true
    std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl;  // true

    return 0;
}