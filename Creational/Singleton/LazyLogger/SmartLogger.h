#pragma once
#define _CRT_SECURE_NO_WARNINGS //turn off deprecation warning for fopen, or use fopen_s
#include <cstdio>
#include <memory>
#include <string>

class SmartLogger
{
	struct Deleter {
		void operator()(SmartLogger* p) {
			delete p;
		}
	};

	FILE* m_pStream;
	std::string m_Tag;
	SmartLogger();
	~SmartLogger();
	inline static std::unique_ptr<SmartLogger, Deleter> m_pInstance{};
public:
	SmartLogger(const SmartLogger&) = delete;
	SmartLogger& operator =(const SmartLogger&) = delete;
	static SmartLogger& Instance();
	void WriteLog(const char* pMessage);
	void SetTag(const char* pTag);
};

