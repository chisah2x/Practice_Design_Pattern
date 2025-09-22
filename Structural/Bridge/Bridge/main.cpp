#include "Line.h"
#include "Circle.h"
#include "GDI.h"
#include "OpenGL.h"

//Static bridge
class Line_GDI : public Line, private GDI {
	using Line::Line ;
public:
	void Draw()override {
		RenderLine(GetStart(), GetEnd()) ;
		Show() ;
	}
};

void RenderShape(Shape *s, Renderer *r) {
	s->SetRenderer(r) ;
	s->Draw() ;
	r->Show() ;
}
int main(int argc, char *argv[]) {
	Line_GDI lg{{100, 100}, {100, 300}} ;
	lg.Draw() ;

	
	/*Line line{{100, 100}, {100, 300}} ;
	Circle circle{{400, 400}, 100} ;

	GDI gdi{} ;
	OpenGL opengl{} ;

	RenderShape(&circle, &opengl) ;*/
	return 0 ;
}
