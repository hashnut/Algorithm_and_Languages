# CPP Review
> CPP Review following lectures frome [here](https://modoocode.com/135)
>
> Also cover other references & codes

### [2. References](https://github.com/hashnut/CPP_Review/blob/main/codes/2.cpp)

Reference is a nickname. Therefore it cannot be used alone, it needs original name to exist!

+ Can't assign literals with reference, but with `const int &ref = 4` is allowed. When used as function's return type, it vanishes as the function returns, but const, such as `const int& f = function()` can extend return value's lifespan

### 4. Object Oriented Programming

[What is class? It's a template used to create an instance](https://github.com/hashnut/CPP_Review/blob/main/codes/4-1.cpp). 
+ [You should know about function overloading(with type conversion issue), and constructor(also default constructor).](https://github.com/hashnut/CPP_Review/blob/main/codes/4-2.cpp)
+ [Note there is also `default copy constructor` in c++, but don't forget to free memories like `char*` type!](https://github.com/hashnut/CPP_Review/blob/main/codes/4-3.cpp)


