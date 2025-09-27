#include <iostream>
#include <vector>
#include "String.h"
#include <boost/flyweight.hpp>

using SharedString = boost::flyweights::flyweight<WithoutFlyweight::String> ;
int && Add(int x,int y) {
	return x + y ;
}
int main(){
	auto && p = Add(3,5) ;
	using namespace WithoutFlyweight ;
	std::vector<SharedString> strings{} ;
	SharedString s1("C++") ;
	for(int i = 0 ; i < 100 ; ++i) {
		strings.push_back(s1) ;
	}
	
	String::ShowCount() ;
	//StringInfo::ShowCount() ;
	
}