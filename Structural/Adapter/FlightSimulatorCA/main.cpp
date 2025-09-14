#include "Input.h"
#include <iostream>
#include <chrono>
#include <thread>

#include "AccelAdapter.h"
#include "Keyboard.h"

void Game(Input *pInput) {
	using namespace std ;
	int count{5} ;
	while(count != 0 ) {
		std::cout << "===========================\n" ;
		if(pInput->Up()) {
			std::cout << "Pitch up\n" ;
		}else if(pInput->Down()) {
			std::cout << "Pitch down\n" ;
		}else {
			std::cout << "Plane is level\n" ;
		}

		if(pInput->Left()) {
			std::cout << "Plane is turning left\n" ;
		}else if(pInput->Right()) {
			std::cout << "Plane is turning right\n" ;
		}else {
			std::cout << "Plane is flying straight\n" ;
		}
		std::cout << '\n' ;
		std::this_thread::sleep_for(1s) ;
		--count ;
	}
}
int main() {
	//Keyboard k ;
	AccelAdapter k ;
	//k.GetVerticalAxis() ;
	Game(&k) ;
}