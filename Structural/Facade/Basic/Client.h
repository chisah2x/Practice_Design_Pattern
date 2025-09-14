#pragma once
class Facade ;
class Client
{
	Facade *m_pF ;
public:
	Client() ;
	~Client() ;
	void Invoke() ;
};

