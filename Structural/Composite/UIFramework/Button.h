#pragma once
#include "Widget.h"
class Button :
	public Widget
{

public:
	void AddChild(Widget* pWidget) override;
	void Paint() override;
	void RemoveChild(Widget* pWidget) override;
	void SetVisibility(bool visibility) override;
};

