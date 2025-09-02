#include "BaseSingleton.h"
#include "Logger.h"

//class GameManager : public BaseSingleton<GameManager> {
//private:
//	GameManager() = default;
//	friend class BaseSingleton<GameManager>;
//public:
//	void LoadAssets() {
//
//	}
//	void Run() {
//
//	}
//};

class GameManager : public BaseSingleton<GameManager> {
	MAKE_SINGLETON(GameManager);
public:
	void LoadAssets() {

	}
	void Run() {

	}
};
void OpenConnection() {
	Logger& lg = Logger::Instance();
	lg.WriteLog("Attempting to open a connection");
}
int main() {
	GameManager& gm = GameManager::Instance();
	//auto gm2 = gm ;
	gm.LoadAssets();

	std::thread t1{ []() {
		Logger& lg = Logger::Instance();
		lg.WriteLog("Thread 1 has started");
	} };
	std::thread t2{ []() {
		Logger& lg = Logger::Instance();
		lg.WriteLog("Thread 2 has started");
	} };
	t1.join();
	t2.join();
}

/*
Singleton design pattern in C++ using the Curiously Recurring Template Pattern (CRTP).

Singleton Pattern Implementation
- The Singleton pattern allows multiple classes to behave as singletons by reusing singular behavior through inheritance.
- A base Singleton class is created with a protected constructor, ensuring instances cannot be copied or assigned.

Curiously Recurring Template Pattern (CRTP)
- A child class, such as GameManager, inherits from the base Singleton, passing itself as a template parameter.
- The child class must have a private constructor and make the base Singleton a friend to allow instance creation.

Macro for Simplification
- A macro can simplify the process of making classes singletons by automating the private constructor and friendship setup.
- The logger class can also inherit from the base Singleton, demonstrating flexibility in applying the Singleton pattern across different classes.
*/