#pragma once
#include "Component.h"
class Leaf :
	public Component
{

public:
	void Add(Component* pComponent) override;
	Component* GetChild(int index) override;
	void Operation() override;
	void Remove(Component* pComponent) override;
};

