#include "SmartLogger.h"
//#include "LazyLogger.h"

void OpenConnection() {
	SmartLogger& lg = SmartLogger::Instance();
	lg.WriteLog("Attempting to open a connection");
}
int main() {
	SmartLogger& lg = SmartLogger::Instance();
	lg.SetTag("192.168.1.101");
	lg.WriteLog("Application has started");
	OpenConnection();
	lg.WriteLog("Application is shutting down");
}

/*
now destructor is getting invoded automatically.
but if user: auto *p = &lg; delete p; //undefined behavior

now make private deleter but unique_ptr needs to access it so provide own deleter.
*/