#include "Logger.h"
void OpenConnection() {
	Logger& lg = Logger::Instance();
	lg.WriteLog("Attempting to open a connection");
}
int main() {
	Logger& lg = Logger::Instance();
	lg.SetTag("192.168.1.101");
	lg.WriteLog("Application has started");
	OpenConnection();
	lg.WriteLog("Application is shutting down");
}

/*
The constructor opens the log file, while the destructor ensures it is closed properly.
If multiple logger instances are created, leading to undefined behavior when trying to write to the same log file.

If a user does not use a reference when acquiring the logger instance, it can lead to crashes due to shallow copying of the stream pointer.
To prevent copying, the copy constructor and assignment operator are declared with the delete modifier, enforcing the use of references.

if a class manages resources => rule of three and In c++11 rule of five.
not necessary in this case since the logger instance is global.

Using a pointer instead of a reference 
Pointers: Require manual memory management, can lead to null pointer dereferencing, and need null checks.
-> accidentally delete it, which would leave other parts of the program trying to access a resource that no longer exists.
References: Are safer, cleaner, and ensure that you always have a valid object to work with.
*/