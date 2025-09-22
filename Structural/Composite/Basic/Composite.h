#pragma once
#include <vector>

#include "Component.h"
class Composite :
	public Component
{
	std::vector<Component *> m_Components{} ;
public:
	void Add(Component* pComponent) override;
	Component* GetChild(int index) override;
	void Operation() override;
	void Remove(Component* pComponent) override;
};

