#include "Application.h"
#include <algorithm>
#include <map>

void Foo(std::unique_ptr<int> u1, std::unique_ptr<int> u2){
}

template<typename Type, typename...Args>
std::unique_ptr<Type> MakeUnique(Args&&...args) {
	return std::unique_ptr<Type>{
		new Type{std::forward<Args>(args)...}
	} ;
}
int main() {
	/*
	Purpose
•	_CRTDBG_ALLOC_MEM_DF: Enables debug heap allocations, allowing the runtime to track memory allocations and deallocations.
•	_CRTDBG_LEAK_CHECK_DF: Tells the runtime to automatically check for memory leaks when the program exits and report them in the Output window.
	*/
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) ;
	Application app ;
	app.New() ;
	app.Open() ;
	app.Save() ;


	//examples
	int *p = new int{5} ;

	delete p ;

	std::unique_ptr<int> p2 {new int{5}} ;

	auto p3 = std::make_unique<int>(5) ;

	/*Foo(
		std::unique_ptr<int>{new int{ 1 }},
		std::unique_ptr<int>{new int{ 2 }}
	);
	The first line manually allocates memory for integers and wraps them in unique_ptr, while the second line uses make_unique to achieve the same result in a more concise and safer way.
	*/
	
	Foo(
		std::make_unique<int>(1),
		std::make_unique<int>(2)
	) ;

	auto p4 = std::make_shared<int>(5) ;
	
	std::shared_ptr<int> p5 {new int{5}} ;


	std::multimap<int, int> m ;
	m.insert(std::pair<int,int>{1,2}) ;
	m.insert(std::make_pair(1,2)) ;
	//m[1] = 2 ;

	auto t1 = std::make_tuple(1, "Hello", 5) ;
	
	std::tuple<int, const char *, int> t2{1, "Hello", 5} ;
	
}
