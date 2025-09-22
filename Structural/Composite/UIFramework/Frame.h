#pragma once
#include <vector>

#include "Widget.h"
class Frame :
	public Widget
{
	std::vector<Widget*> m_Children{} ;
public:
	void AddChild(Widget* pWidget) override;
	void Paint() override;
	void RemoveChild(Widget* pWidget) override;
	void SetVisibility(bool visibility) override;

	Frame* GetFrame() override;
};

