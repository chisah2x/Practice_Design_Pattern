#include "Button.h"

#include <iostream>

void Button::AddChild(Widget* pWidget) {
}

void Button::Paint() {
	if(m_IsVisible)
		std::cout << "Button\n" ;
}

void Button::RemoveChild(Widget* pWidget) {
}

void Button::SetVisibility(bool visibility) {
	std::cout << std::boolalpha ;
	std::cout << "[Button] Visibility:" << visibility << std::endl; 
	m_IsVisible = visibility ;
}
