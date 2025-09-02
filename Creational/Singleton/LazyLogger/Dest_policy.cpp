//#include "Logger.h"
//Logger* Logger::m_pInstance = nullptr;
//Logger::Logger() {
//	std::cout << __FUNCSIG__ << std::endl;
//	m_pStream = fopen("applog.txt", "w");
//}
//
//Logger& Logger::Instance() {
//	if(m_pInstance == nullptr) {
//			m_pInstance = new Logger{};
//		}
//	return *m_pInstance;
//}
//
//Logger::~Logger() {
//	std::cout << __FUNCSIG__ << std::endl;
//	fclose(m_pStream);
//}
//
//void Logger::WriteLog(const char* pMessage) {
//	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage); //maybe written in file buffer
//	fflush(m_pStream); //ensure it is written to file
//}
//
//void Logger::SetTag(const char* pTag) {
//	m_Tag = pTag;
//}

//A destructor is a special function that cleans up resources when an object is no longer needed
//not calling delete as it maybe use somewhere else in the program

//If an object is created dynamically using new and not properly deleted using delete, the destructor will not be called. 
// This can lead to memory leaks, as the resources allocated for that object are not released.

//Global or Static Instance: If the singleton instance is a global or static variable, 
// its destructor will not be called until the program terminates.

/*
Using Smart Pointers

Smart pointers act like a reliable friend that automatically deletes the object when the program ends, ensuring proper cleanup.
This prevents memory leaks and ensures that resources are released correctly.
Using atexit Function

The atexit function allows us to set a reminder to clean up resources right after the program ends.
This ensures that the destructor is called, and resources are released, keeping the application running smoothly.

Global and Static Objects: In C++, global and static objects are created before the main() function starts and destroyed after main() ends. This means their lifetime is tied to the entire program.
Destruction Order: The order of destruction for global and static objects across different translation units (files) is unspecified. This means that if your Logger instance is used in the destructor of another global or static object, there’s a risk that the Logger might already be destroyed when that destructor is called.
Potential Issues:
If the Logger instance is destroyed first, and then another global or static object tries to access it in its destructor, it may lead to accessing a dangling pointer (a pointer that points to a memory location that has been freed).
This can cause undefined behavior, such as crashes or data corruption, because the Logger instance may no longer exist when it is needed.

Conclusion:
To avoid these issues, it’s best to ensure that the Logger instance is not used in global or static contexts. Instead, it should be accessed only within the scope of functions or classes where you can guarantee its availability. This way, you maintain control over the Logger's lifecycle and avoid potential pitfalls.
*/