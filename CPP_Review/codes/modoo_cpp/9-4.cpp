/*

    9-4 : 템플릿 메타 프로그래밍 (Template Meta programming)
    
    템플릿 메타 프로그래밍으로 작성된 코드는 모두 컴파일 타임에 모든 연산이 끝난다.
    즉, 프로그램 실행 속도를 향상시킬 수 있다는 장점이 있다(컴파일 타임은 늘어남)


    컴파일러는 기본적으로 인자를 '값'으로 인식한다.
    그러므로 애해한 경우 타입을 받아야 한다면 반드시 typename을 명시해 주어야 한다.

    template<typename a, typename b>
    struct test<a, typename something<a, b>::result> {
        static const result = ...;
    }


    단위(Unit) 라이브러리 : 
    템플릿 메타 프로그래밍은 단위 계산에 강점을 보인다! 




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

template <int X, int Y>
struct GCD {
  static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
  static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
 private:
  const static int _gcd = GCD<N, D>::value;

 public:
  typedef Ratio<N / _gcd, D / _gcd> type;
  static const int num = N / _gcd;
  static const int den = D / _gcd;
};
template <class R1, class R2>
struct _Ratio_add {
  using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
  using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
  using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
  using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};


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

/*

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

*/

template <int N>
struct INT {
    static const int num = N;
};

template <typename a, typename b>
struct add2 {
    typedef INT<a::num + b::num> result;
};

template <typename a, typename b>
struct divide {
    typedef INT<a::num / b::num> result;
};

using one = INT<1>;
using two = INT<2>;
using three = INT<3>;

template <typename N, typename d>
struct check_div {
    static const bool result =
        (N::num % d::num == 0) || check_div<N, typename add2<d, one>::result>::result;
};

template <typename N>
struct _is_prime {
    static const bool result = !check_div<N, two>::result;
};

template <>
struct _is_prime<two> {
    static const bool result = true;
};

template <>
struct _is_prime<three> {
    static const bool result = true;
};

template <typename N>
struct check_div<N, typename divide<N, two>::result> {
    static const bool result = (N::num % (N::num / 2) == 0);
};


template <int N>
struct is_prime {
    static const bool result = _is_prime<INT<N>>::result;
};

template <typename U, typename V, typename W>
struct Dim {
  using M = U;
  using L = V;
  using T = W;

  using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_ {
  typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
              typename Ratio_add<typename U::L, typename V::L>::type,
              typename Ratio_add<typename U::T, typename V::T>::type>
      type;
};

template <typename U, typename V>
struct subtract_dim_ {
  typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
              typename Ratio_subtract<typename U::L, typename V::L>::type,
              typename Ratio_subtract<typename U::T, typename V::T>::type>
      type;
};

template <typename T, typename D>
struct quantity {
  T q;
  using dim_type = D;

  quantity operator+(quantity<T, D> quant) {
    return quantity<T, D>(q + quant.q);
  }

  quantity operator-(quantity<T, D> quant) {
    return quantity<T, D>(q - quant.q);
  }

  quantity(T q) : q(q) {}
};




int main() {

    int arr[3] = {1, 2, 3};

    Array<int, 3> arr_w(arr);

    arr_w.print_all();

    std::cout << (typeid(Array<int, 3>) == typeid(Array<int, 5>)) << std::endl;


    // 컴파일 타임에 수행된다!
    typedef Int<1> one;
    typedef Int<2> two;

    //typedef add<one, two>::result three;

    //std::cout << "Addition result : " << three::num << std::endl;


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