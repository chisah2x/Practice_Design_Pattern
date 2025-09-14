#include <iostream>
#include <string>
#include <windows.h>

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) ;
	CONSOLE_SCREEN_BUFFER_INFO csinfo{} ;
	if(!GetConsoleScreenBufferInfo(hConsole, &csinfo)) {
		std::cout << "Error getting console information\n" ;
		return -1 ;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED) ;
	std::string text{"Hello world"} ;
	DWORD written{} ;
	WriteConsoleA(hConsole, text.c_str(), text.length(),&written, nullptr ) ;
	
	SetConsoleTextAttribute(hConsole, csinfo.wAttributes) ;
	std::cout << "Using cout\n" ;
	printf("Using printf\n") ;
}