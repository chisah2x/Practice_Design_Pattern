#pragma once
#include "Subject.h"
class RealSubject;
class Proxy :
	public Subject
{
	RealSubject* m_pSubject;
public:
	Proxy();
	~Proxy();
	void Request() override;
};

