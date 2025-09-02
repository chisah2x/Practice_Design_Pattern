#pragma once
#define _CRT_SECURE_NO_WARNINGS //turn off deprecation warning for fopen, or use fopen_s
#include <cstdio>
#include <memory>
#include <string>

class LazyLogger
{
	FILE* m_pStream;
	std::string m_Tag;
	LazyLogger();
	//inline static LazyLogger *m_Instance;
	static LazyLogger *m_pInstance;
	~LazyLogger();
public:

	LazyLogger(const LazyLogger&) = delete;
	LazyLogger& operator =(const LazyLogger&) = delete;
	static LazyLogger& Instance();
	void WriteLog(const char* pMessage);
	void SetTag(const char* pTag);
};

