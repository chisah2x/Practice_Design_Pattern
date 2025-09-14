#pragma once
class A ;
class B ;
class C ;
class Facade
{
	A * m_pA ;
	B * m_pB ;
	C * m_pC ;
public:
	Facade() ;
	~Facade();
	void Use() ;
};

