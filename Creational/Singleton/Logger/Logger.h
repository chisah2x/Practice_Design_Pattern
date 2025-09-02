#pragma once
#define _CRT_SECURE_NO_WARNINGS //turn off deprecation warning for fopen, or use fopen_s
#include <cstdio>
#include <string>

class Logger
{
	FILE* m_pStream;
	std::string m_Tag;
	Logger();
	static Logger m_Instance;
public:
	Logger(const Logger&) = delete;
	Logger& operator =(const Logger&) = delete;
	static Logger& Instance();
	~Logger();
	void WriteLog(const char* pMessage);
	void SetTag(const char* pTag);
};

