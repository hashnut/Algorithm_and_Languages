/* 레퍼런스는 별명이다
 * 
 * 레퍼런스는 정의 시에 반드시 누구의 별명인지 명시해야 한다
 *
 *
 *
 *
 */
#include <iostream>

int& function();
int& function(int &a);

using namespace std;

int main()
{
	printf("Hello World!\n");
	
	// It's impossible to use '&' like the following,
	// Because '&' is just a nickname for existing variable
	// int & another_a;

	int a = 10;
	int &another_a = a; // another_a a becomes reference to a

	int b = 3;
	another_a = b; // It means same with a = b

	// Reference could not exist on MEMORY
	
	// cin get `user_input` as refernce
	int user_input;
	std::cin >> user_input;

	// It's error because you try to change the value of literal
	//int &ref = 4;
	const int &ref = 4;
	int c = ref; // It is same as a = 4;

	// It is "illegal" to use references of references, array of references, and
	// pointers to references
	// "int &arr[2] = {a, b};"
	// "WHY?" : Because... generally, reference does not take up memory,
	// while pointers always have to be stored in "MEMORY" addresses
	
	// But references of array is possible
	int arr[3] = {1, 2, 3};
	int (&ref2)[3] = arr;

	ref2[0] = 2;
	ref2[1] = 3;
	ref2[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;

	// Segmentation fault!
	// b = function();
	// "WHY?" : return value "a" is local variable, so that it vanishes as the function
	// returns, so now "b" references to the non-existing value
	// It is called "Dangling reference" : Value to be referenced is gone


	// It is OK, because reference source "b" is still alive!
	b = 2;
	c = function(b); // same as "c = 5"
 
	
	// "IMPORTANT EXCEPTION" : when you take return value of reference type
	// with "const", its life is elongated until reference variable is gone
	// In this case, until "f" is gone
	const int& f = function();
	std::cout << "c : " << c << endl;
	
	return 0;


}

int& function()
{
	int a = 2;
	return a;
}

int& function(int &a)
{
	a = 5;
	return a;
}
