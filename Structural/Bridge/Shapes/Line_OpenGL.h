#pragma once
#include "Point.h"
#include "Shape.h"
#include <simple2d.h>
class Line_OpenGL :
	public Shape
{
	inline static Point m_Start{};
	inline static Point m_End{};
	S2D_Window* m_pWindow{};
public:
	Line_OpenGL(const Point& m_start, const Point& m_end, S2D_Window* m_p_window)
		:
		m_pWindow(m_p_window) {
		m_Start = m_start;
		m_End = m_end;
	}
	static void Render();
	void Draw() override;
};

