#include <iostream>
#include <string>


int main() {
	
	std::string FirstPart, SecondPart, WholePart;
	double Number;
	std::cout << "Enter the integer part of the number: ";
	std::cin >> FirstPart;
	std::cout << "Enter the part of the number after the dot: ";
	std::cin >> SecondPart;
	WholePart = FirstPart + "." + SecondPart;
	
	std::cout << "String type: " << WholePart << std::endl;
	Number = std::stod(WholePart);
	std::cout <<"Double type: " << Number << std::endl;
	
}
