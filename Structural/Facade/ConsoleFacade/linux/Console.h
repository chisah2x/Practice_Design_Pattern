#include <string>
enum class Color{RED, GREEN, BLUE, WHITE} ;
class Console{
	Console() ;
	static int GetColor(Color color) ;
public:
	static void Write(const std::string &text, Color color = Color::WHITE) ;	
	static void WriteLine(const std::string &text, Color color = Color::WHITE) ;	

} ;
