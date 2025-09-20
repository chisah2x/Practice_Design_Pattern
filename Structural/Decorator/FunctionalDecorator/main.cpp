#include <iostream>

int Square(int x) {
	return x * x ;
}
int Add(int x, int y) {
	return x + y ;
}
float Divide(float x,float y) {
	return x / y ;
}
template<typename Function>
auto PrintResult(Function func) {
	return [func](auto&&...args) {
		std::cout << "Result is : " ;
		return func(args...) ;
	};
}
template<typename Function>
auto PrintHeader(Function func) {
	return [func](auto&&...args) {
		std::cout << "=====================\n" ;
		return func(args...) ;
	};
}
template<typename Function>
auto SafeDivision(Function func) {
	return [func](auto a, auto b) {
		if(b == 0){
			std::cout << "Divide by zero " ;
			b=1 ;
		}
		return func(a,b) ;
	};
}

int main() {
	/*auto result = Square(5) ;
	std::cout << "Result is:" << result << std::endl;
	result = Add(8,2) ;
	std::cout << "Result is:" <<result << std::endl;*/

	auto result = PrintResult(Square) ;
	std::cout << result(5) << std::endl;

	auto add = PrintResult(Add) ;
	std::cout << add(3,5) << std::endl ;

	auto div = PrintHeader(PrintResult(SafeDivision(Divide))) ;
	std::cout << div(3,0) << std::endl; 

}