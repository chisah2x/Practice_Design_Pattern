#include "Proxy.h"

#include <iostream>

#include "RealSubject.h"
Proxy::Proxy() {
}

Proxy::~Proxy() {
	delete m_pSubject;
}

void Proxy::Request() {
	if(m_pSubject == nullptr) {
		std::cout << "[Proxy] Creating RealSubject\n";
		m_pSubject = new RealSubject{};
	}
	std::cout << "[Proxy] Additional behavior\n\n";
	m_pSubject->Request();
}
