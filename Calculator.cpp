#include <iostream>
#include <string>
#include <sstream>


double result(double a, double b, char operation) {
	std::string Exc;
	if(operation == '+') return a + b;
	if(operation == '-') return a - b;
	if(operation == '/') {
		try{
			a / b;
			if(b == 0) throw(Exc);
			else return a / b;
		}
		catch(std::string myExc) {
			std::cout << "Dividing by zero condition!\n";
			exit(0);
		}
	}
	
	if(operation == '*') return a * b;
}


int main() {
	
	double numA, numB;
	std::string buffer, operatorException = "Wrong operator!\n";
	char operation;
	
	std::cout << "Enter number >> operation >> number: ";
	std::cin >> buffer;
	std::stringstream buffer_stream(buffer);
	
	try{
		buffer_stream >> numA >> operation >> numB;
		if(operation != '+' && operation != '-' &&
		 	operation != '/' && operation != '*') {
			throw(operatorException);
		}
		
	}
	catch(std::string myExc) {
		std::cout << myExc;
		exit(0);
	}

	std::cout <<"Before: " << numA << operation << numB << std::endl;
	std::cout <<"After calculation: ";
	std::cout << result(numA, numB, operation);
}


