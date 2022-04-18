# CPP Review
> CPP Review following lectures from [here](https://modoocode.com/135), Effective C++ and Effective Modern C++.
>
> Also cover other references & codes

### [1. Namespace](https://koreanfoodie.me/809)

### [2. References](https://koreanfoodie.me/810)

Reference is a nickname. Therefore it cannot be used alone, it needs original name to exist!

+ Can't assign literals with reference, but with `const int &ref = 4` is allowed. When used as function's return type, it vanishes as the function returns, but const, such as `const int& f = function()` can extend return value's lifespan

### [3. New and Delete](https://koreanfoodie.me/811)

### 4. Object Oriented Programming

- [1. What is class? It's a template used to create an instance](https://koreanfoodie.me/812)
- [2. You should know about function overloading(with type conversion issue), and constructor(also default constructor).](https://koreanfoodie.me/814)
- [3. Note there is also `default copy constructor` in c++, but don't forget to free memories like `char*` type!](https://koreanfoodie.me/815)
- [4. static variable in class : class shares identical variable. static function : class shares identical function. `static` type variable/function does not belong to `object`, but `class`](https://koreanfoodie.me/818)
- [5. Custom string class](https://koreanfoodie.me/821)
- [6. explicit and mutable](https://koreanfoodie.me/823)

### 5. Operator Overloading
- [1. Operator Overloading : Basics](https://koreanfoodie.me/825)
- [2. IO, Operator++, Type Casting](https://koreanfoodie.me/826)
- [3. Operator[] Overloading with Nth-Dim Array (Difficult)](https://koreanfoodie.me/827)

### 6. Inheritance and Virtual Functions
- [1. C++ String & Inheritance](https://koreanfoodie.me/830)
- [2. Virtual Functions and Polymorphism](https://koreanfoodie.me/834)
- [3. Virtual Functions and Miscellaneous](https://koreanfoodie.me/835)

### 7. C++ IO
- [1. istream, ostream](https://koreanfoodie.me/837)
- [2. ifstream, ofstream, stringstream](https://koreanfoodie.me/839)

### 8. ...Project



### 9. C++ Templates
- [1. C++ Template](https://koreanfoodie.me/841)
- [2. Variadic Template](https://koreanfoodie.me/845)
- [3. Template Meta Programming](https://koreanfoodie.me/847)
- [4. Template Meta Programming2](https://koreanfoodie.me/891)
- [4-2. Template Meta Programming2-2](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/9-4-2.cpp)


### 10. C++ STL
- [1. C++ STL - Sequence Container](https://koreanfoodie.me/892)
- [2. C++ STL - Associative Container](https://koreanfoodie.me/893)
- [3. C++ STL - Algorithm](https://koreanfoodie.me/935)
- [4. C++ STL - string and string_view](https://koreanfoodie.me/936)

### 11. Exception Handling
- [C++ Exception Handling](https://github.com/hashnut/Algorithms_and_Languages/blob/main/CPP_Review/codes/11-1.cpp)

### 12. Rvalue Reference
- [1. Rvalue Reference and move constructor](https://koreanfoodie.me/806)
- [2. Move semantics, perfect forwarding, and universal reference ](https://koreanfoodie.me/807)

### 13. Smart Pointer
- [1. unique_ptr](https://koreanfoodie.me/840)
- [2. shared_ptr, weak_ptr](https://koreanfoodie.me/842)


