#include "Proxy.h"
#include "RealSubject.h"
#include "Subject.h"

int main() {
	//Subject* s = new RealSubject{};

	Subject* s = new Proxy{};
	s->Request();
	s->Request();
	s->Request();
	delete s;
}
