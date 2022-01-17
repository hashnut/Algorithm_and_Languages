# CPP Review
> CPP Review following lectures from [here](https://modoocode.com/135), Effective C++ and Effective Modern C++.
>
> Also cover other references & codes

### [2. References](https://github.com/hashnut/CPP_Review/blob/main/codes/2.cpp)

Reference is a nickname. Therefore it cannot be used alone, it needs original name to exist!

+ Can't assign literals with reference, but with `const int &ref = 4` is allowed. When used as function's return type, it vanishes as the function returns, but const, such as `const int& f = function()` can extend return value's lifespan

### 4. Object Oriented Programming

- [1. What is class? It's a template used to create an instance](https://github.com/hashnut/CPP_Review/blob/main/codes/4-1.cpp)
- [2. You should know about function overloading(with type conversion issue), and constructor(also default constructor).](https://github.com/hashnut/CPP_Review/blob/main/codes/4-2.cpp)
- [3. Note there is also `default copy constructor` in c++, but don't forget to free memories like `char*` type!](https://github.com/hashnut/CPP_Review/blob/main/codes/4-3.cpp)
- [4. static variable in class : class shares identical variable. static function : class shares identical function. `static` type variable/function does not belong to `object`, but `class`](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/4-4.cpp)

### 5. Operator Overloading
- [1. Operator Overloading : Basics](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/5-1.cpp)
- [2. IO, Operator++, Type Casting](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/5-2.cpp)
- [3. Operator[] Overloading with Nth-Dim Array (Difficult)](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/5-3.cpp)

### 6. Inheritance and Virtual Functions
- [1. C++ String & Inheritance](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/6-1.cpp)
- [2. Virtual Functions and Polymorphism](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/6-2.cpp)
- [3. Virtual Functions and Miscellaneous](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/6-3.cpp)

### 7. C++ IO
- [1. istream, ostream](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/7-1.cpp)
- [2. ifstream, ofstream, stringstream]()

### 8. ...Project



### 9. C++ Templates
- [1. C++ Template](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/9-1.cpp)
- [2. Variadic Template](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/9-2.cpp)
- [3. Template Meta Programming](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/9-3.cpp)
- [4. Template Meta Programming2](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/9-4.cpp)
- [4-2. Template Meta Programming2-2](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/9-4-2.cpp)


### 10. C++ STL
- [1. C++ STL - Sequence Container](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/10-1.cpp)
- [2. C++ STL - Associative Container](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/10-2.cpp)
- [3. C++ STL - Algorithm](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/10-3.cpp)
- [4. C++ STL - string and string_view](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/10-4.cpp)

### 11. Exception Handling
- [C++ Exception Handling](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/11-1.cpp)

### 12. Rvalue Reference
- [1. Rvalue Reference and move constructor](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/12-1.cpp)
- [2. Move semantics, perfect forwarding, and universal reference ](https://koreanfoodie.me/807)

### 13. Smart Pointer
- [1. unique_ptr](https://koreanfoodie.me/840)
- [2. shared_ptr, weak_ptr](https://koreanfoodie.me/842)


