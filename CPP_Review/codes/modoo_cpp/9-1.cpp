/*

    9-1 : template <typename T> 는 템플릿 인자로 T를 받으며, 타입의 이름을 명시한다.

    템플릿 특수화(template specialization) : 
        bool과 같은 경우에, 1비트만을 사용하므로, 4/8 바이트를 동일하게 사용하는 것은 큰 낭비이다.
        이와 같이 일부 경우에 대해서 따로 처리하는 것을 템플릿 특수화라고 한다!]
        
        1. 일반적인 경우 : 
        template <typename A, typename B, typename C>
        class test {};

        2. A와 C를 특수화 :
        template <typename B>
        class test<int, B, double> {};

        3. 전부 특수화 : 
        template <>
        class test<int, int, double> {};

        4. bool의 경우 : 
        template <>
        class test<bool> { // 원하는 코드 };


    Sort를 하는데 오름차순이 아닌 내림차순으로 하고 싶다면..?
        1. sort 함수 자체를 바꾼다 -> C를 배운다면 이렇게...
        2. struct / class 타입 내부에서 operator overloading -> 나쁘지 않은 방법
        3. 함수 객체 (Functor)를 사용 -> C++를 배운다면 이렇게! 복잡도 관리나 시간 측면에서 더욱 우수한 방식


    타입이 아닌 템플릿 인자 (non-type template arguments)
        템플릿 인자로 타입만 받을 수 있는 것이 아니다!

        template <typename T, int num = 5> // = 을 사용해 디폴트 인자를 설정할 수 있다.
        T add_num(T t) {
            return t + num;
        }
        add_num<int, 5>(3); 
        add_num<int>(3); // 위와 같은 결과값. Thanks to default template argument


*/

#include <iostream>
#include <string>
#include <vector>
#include <array>

template <typename T>
class Vector {
    T* data;
    int capacity;
    int length;

public:
    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s) {
        if (capacity <= length) {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }

            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    T operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다.
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    void swap(int i, int j) {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

template <>
class Vector<bool> {
    unsigned int* data;
    int capacity;
    int length;

public:
    typedef bool value_type;

    Vector(int n = 1)
        : data(new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0) {
        for (int i = 0; i < capacity; i++) {
            data[i] = 0;
        }
    }

    void push_back(bool s) {
        if (capacity * 32 <= length) {
            unsigned int* temp = new unsigned int[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                temp[i] = data[i];
            }
            for (int i = capacity; i < 2 * capacity; i++) {
                temp[i] = 0;
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        if (s) {
            data[length / 32] |= (1 << (length & 32));
        }

        length++;

    }

    bool operator[](int i) { return (data[i / 32] & (1 << (i % 32))) != 0; }


    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            int prev = i - 1;
            int curr = i;

            if (data[curr / 32] & (1 << (curr % 32))) {
                data[prev / 32] |= (1 << (prev % 32));
            }
            else {
                unsigned int all_ones_except_prev = 0xFFFFFFFF;
                all_ones_except_prev ^= (1 << (prev % 32));
                data[prev / 32] &= all_ones_except_prev;
            }
        }
        length--;
    }

    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

template <typename T>
T max(T& a, T& b) {
    return a > b ? a : b;
}

template <typename Cont, typename Comp>

void bubble_sort(Cont& cont, Comp& comp) {
    for (int i = 0; i < cont.size(); i++) {
        for (int j = i + 1; j < cont.size(); j++) {
            if (!comp(cont[i], cont[j])) {
                cont.swap(i, j);
            }
        }
    }
}

struct Comp1 {
    bool operator()(int a, int b) { return a > b; }
};

struct Comp2 {
    bool operator()(int a, int b) { return a < b; }
};

template <typename T, int num>
T add_num(T t) {
    return t + num;
}



int main() {
    Vector < Vector<int>> vec_2d;


    // int 를 보관하는 벡터를 만든다.
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "-------- int vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "-------- std::string vector -------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

    Vector<bool> bool_vec;
    bool_vec.push_back(true);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);

    std::cout << "-------- bool vector ---------" << std::endl;
    for (int i = 0; i < bool_vec.size(); i++) {
        std::cout << bool_vec[i];
    }
    std::cout << std::endl;

    Comp1 comp1;
    bubble_sort(int_vec, comp1);

    Comp2 comp2;
    bubble_sort(int_vec, comp2);


}
