#include <iostream>
#include <fstream>
#include <string>


int main()
{	
	std::cout << "What is your name?" << std::endl;

	std::string name;
	std::cin >> name;

	std::cout << "My name is " << name << std::endl;
	
	std::ofstream ofile;
	ofile.open("out.log");
	
	ofile << "My name is " << name << std::endl;
	
}