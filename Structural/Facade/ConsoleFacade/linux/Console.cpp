#include "Console.h"
#include <iostream>
Console::Console(){
}
int Console::GetColor(Color color){
	switch(color){
		case Color::RED: 
			system("tput setaf 1") ;
			break ;
		case Color::GREEN:
			system("tput setaf 2") ;
			break ;
		case Color::BLUE:
			system("tput setaf 4") ;
			break ;
	}
	return 0 ;
}
void Console::Write(const std::string &text, Color color ){
	GetColor(color) ;
	std::cout << text << std::flush;
	system("tput sgr0") ;
}
void Console::WriteLine(const std::string &text, Color color ){
	Write(text + '\n', color) ;
} 

