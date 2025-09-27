#include <iostream>
#include <vector>


#include "String.h"
int main(){
	using namespace WithFlyweight ;
	std::vector<String> strings{} ;
	for(int i = 0 ; i < 100 ; ++i) {
		strings.emplace_back("C++") ;
	}
	strings[0] = "Java" ;
	strings[1] = "C++" ;

	String s1 = "C++" ;
	
	String::ShowCount() ;
	StringInfo::ShowCount() ;
	
}