#include <iostream>
#include <string>
#include <sstream>

using namespace std;


enum switches
{
	POWER,
	MAIN_SOCKETS,
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};


int main() {

	int state = 0;
	stringstream buffer;
	string input, temp_out, temp_in, mov_out, lights_in_house;
	int t_in, t_out; 
	int dt = 5;
	int TempColor = 5000;
	for(int i = 0; i < 14; i++) {
		
		std::cout << "Please enter sensors readings\n";
		cout << "Temp outside, Temp inside, Movements outside(yes/no), Lights in the house(on/off):\n";
		getline(cin, input);
		buffer.str(input);
		buffer >> temp_out >> temp_in >> mov_out >> lights_in_house;
		cout << buffer.str() <<'\n';
		buffer.str("");
		buffer.clear();
		
		t_in = stoi(temp_in);
		t_out = stoi(temp_out);

		if(t_out < 0) {
			state |= WATER_PIPE_HEATING;
			cout << "Water pipe heating is on\n";
		}
		else if(t_out > 5) {
			state &= ~WATER_PIPE_HEATING;
			cout << "Water pipe heating is off\n";
		}
		if(t_in < 22) {
			state |= HEATERS;
			cout << "Heaters are on\n";
		}
		if(t_in >= 25) {
			state &= ~HEATERS;
			std::cout << "Heaters are off\n";
		}
		if(t_in >= 30) {
			state |= CONDITIONER;
			std::cout << "Conditioner is on\n";
		}
		if(t_in == 25) {
			state &= ~CONDITIONER;
			std::cout << "Conditioner is off\n";
		}
		if(dt > 16 && mov_out == "yes") {
			state |= LIGHTS_OUTSIDE;
			cout << "Light outside is on\n";
		}
		else if(dt < 5 && mov_out == "yes") {
			state |= LIGHTS_OUTSIDE;
			cout << "Light outside is on\n";
		}
		if(mov_out == "no") {
			state &= ~LIGHTS_OUTSIDE;
			cout << "Light outside is off\n";
		}
		
		if(lights_in_house == "on"){
			state |= LIGHTS_INSIDE;
			cout << "Lights in the house are on\n";
		} 
		else if(lights_in_house == "off") {
			state &= ~LIGHTS_INSIDE;
			cout << "Lights in the house are off\n";
		}
		
		if(dt >= 16 && lights_in_house == "on") { // func
			cout << "DT = " << dt;
			state |= LIGHTS_INSIDE;
			TempColor -= 575 * (dt - 16);
			if(dt >= 20) TempColor = 2700;
			cout << "Light temp changin " <<TempColor << "K\n";
		}
		if(dt >= 0 && dt < 16 && lights_in_house == "on") cout << "Temp color = 5000k\n";
				
		
		dt+=2;
		if(dt >= 24) dt = 0;
	}
	
			
}



