#include <simple2d.h>

#include "Circle.h"
#include "Circle_OpenGL.h"
#include "Line.h"
#include "Line_OpenGL.h"

void RenderShape(Shape *pShape) {
	pShape->Draw() ;
}
void Software() {
	Window window{} ;
	window.Show() ;
	Line l{{100,100}, {300, 300}, &window} ;
	//l.Draw() ;
	Circle c{{500, 500}, 50, &window} ;
	//c.Draw() ;

	RenderShape(&l) ;
	RenderShape(&c) ;
	window.Run() ;
}

void OpenGL() {
	S2D_Window *pWin = S2D_CreateWindow("MainWindow", 800, 600, nullptr, &Circle_OpenGL::Render, 
		S2D_RESIZABLE) ;
	//Line_OpenGL l{{100,100}, {300, 300}, pWin} ;
	//l.Draw() ;
	Circle_OpenGL c{{300, 300}, 100, pWin} ;
	c.Draw() ;
	S2D_Show(pWin) ;
	S2D_FreeWindow(pWin) ;
}
int main(int argc, char *argv[]){
	OpenGL() ;
	return 0 ;
}