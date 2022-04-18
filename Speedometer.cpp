#include <iostream>
#include <string>


bool compareSpeed(double value, double reference, double epsilon) {
	return (value <= reference + epsilon);
}

void checkLimits(double &currentSpeed) {
	double delta = 0.01;
	if(currentSpeed <= delta) {
		currentSpeed = 0.00;
		std::cout << "Car Stoped!" << std::endl;
	}
	else if(currentSpeed > 150.00){
		currentSpeed = 150.00;
		std::cout <<"Max Speed limit 150 km/h" << std::endl;	
	} 
}

int main() {
	double speed_value, currentSpeed;
	char speed_str[100];
	
	do{
		std::cout <<"Please set car speed: ";
		std::cin >> speed_value;
		currentSpeed += speed_value;
		checkLimits(currentSpeed);
		
		std::sprintf(speed_str,"Current speed: %.1f", currentSpeed);
		std::cout << speed_str << std::endl;
		
		
	}while(!compareSpeed(currentSpeed, 0.0, 0.01));
	
}
