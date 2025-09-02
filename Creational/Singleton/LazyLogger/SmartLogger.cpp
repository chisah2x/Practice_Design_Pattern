#include "SmartLogger.h"
#include <iostream>
//SmartLogger SmartLogger::m_pInstance;

SmartLogger::SmartLogger() {
	m_pStream = fopen("applog.txt", "w");
}

SmartLogger& SmartLogger::Instance() {
	if(m_pInstance == nullptr) {
			//m_Instance = new SmartLogger{};
		m_pInstance.reset(new SmartLogger{});
	}
	return *m_pInstance;
}

SmartLogger::~SmartLogger() {
	fclose(m_pStream);
}

void SmartLogger::WriteLog(const char* pMessage) {
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage); //maybe written in file buffer
	fflush(m_pStream); //ensure it is written to file
}

void SmartLogger::SetTag(const char* pTag) {
	m_Tag = pTag;
}
