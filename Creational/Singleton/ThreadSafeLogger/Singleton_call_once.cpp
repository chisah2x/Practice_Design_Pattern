/*
The lecture focuses on the usage of the `call_once` function introduced in C++11, which ensures that a callable object is executed exactly once, even when called from multiple threads.

Usage of `call_once`
- The function accepts a flag and a callable (like a function pointer, Lambda expression, or functor).
- It guarantees that the callable is invoked only once, regardless of how many threads attempt to call it concurrently.

Comparison with Other Methods
- While `call_once` is useful, the lecture suggests preferring function-local static variables for initialization, as they are guaranteed to occur only once and may be more efficient.
- For non-C++11 environments, alternatives like `ExecuteOnce` on Windows or `pthread_once` on Linux can be used, but caution is advised when using native threads.


#include "Logger.h"
#include <iostream>
Logger* Logger::m_pInstance = nullptr;
std::mutex Logger::m_Mtx;

Logger::Logger() {
	std::cout << __FUNCSIG__ << std::endl;
	m_pStream = fopen("applog.txt", "w");
	atexit([]() {
		delete m_pInstance;
		});
}

std::once_flag flag;
Logger& Logger::Instance() {
	std::call_once(flag, []() {
			m_pInstance = new Logger{};
			});
	return *m_pInstance;	
}

Logger::~Logger() {
	std::cout << __FUNCSIG__ << std::endl;
	fclose(m_pStream);
}

void Logger::WriteLog(const char* pMessage) {
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage);
	fflush(m_pStream);
}

void Logger::SetTag(const char* pTag) {
	m_Tag = pTag;
}
*/

#include <iostream>
#include <fstream>
#include <mutex>
#include <string>

class Logger {
public:
    // Static method to get the instance of the Logger
    static Logger& getInstance() {
        std::call_once(initInstanceFlag, &Logger::initInstance);
        return *instance;
    }

    // Method to log messages
    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(logMutex);
        logFile << message << std::endl;
    }

private:
    Logger() {
        logFile.open("log.txt", std::ios::out | std::ios::app);
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    static void initInstance() {
        instance = new Logger();
    }

    static Logger* instance;
    static std::once_flag initInstanceFlag;
    std::ofstream logFile;
    std::mutex logMutex;
};

// Initialize static members
Logger* Logger::instance = nullptr;
std::once_flag Logger::initInstanceFlag;

//int main() {
//    // Example usage
//    Logger::getInstance().log("This is a log message.");
//    Logger::getInstance().log("Logging another message.");
//
//    return 0;
//}