#include "Client.h"
#include "Facade.h"
Client::Client() {
	m_pF = new Facade{} ;
}

Client::~Client() {
	delete m_pF ;
}

void Client::Invoke() {
	m_pF->Use() ;
}
