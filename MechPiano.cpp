#include <iostream>
#include <string>


enum note {
	C = 2,
	D = 4,
	E = 8,
	F = 16,
	G = 32,
	A = 64,
	B = 128
};


int main() {
	std::string s[12];
	int melody[12];
	for(int i = 0; i < 2; i++) {
		std::cout << "Combination:" << i << " ";
		std::cin >> s[i];
		std::cout << std::endl;
	}
	
	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < s[i].length(); j++) {
			melody[i] = s[i][j] - 48;
			if(note(1 << melody[i]) & C) std::cout << "DO ";
			else if(note(1 << melody[i]) & D) std::cout << "RE ";
			else if(note(1 << melody[i]) & E) std::cout << "MI ";
			else if(note(1 << melody[i]) & F) std::cout << "FA ";
		    else if(note(1 << melody[i]) & G) std::cout << "SOL ";
			else if(note(1 << melody[i]) & A) std::cout << "LA ";
			else if(note(1 << melody[i]) & B) std::cout << "SI ";
		}
		std::cout << "\n";
	}
	

}

