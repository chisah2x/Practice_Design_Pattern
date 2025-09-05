#pragma once
#include "Creator.h"
class ConcreateCreator :
    public Creator
{
public:
	Product* Create() override;

};

