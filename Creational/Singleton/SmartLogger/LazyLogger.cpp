#include "LazyLogger.h"
LazyLogger* LazyLogger::m_pInstance;

LazyLogger::LazyLogger() {
	m_pStream = fopen("applog.txt", "w");
	atexit([]() { //register cleanup function to be called at program exit
		if (m_pInstance != nullptr) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
		});
}

LazyLogger& LazyLogger::Instance() {
	if (m_pInstance == nullptr) {
		m_pInstance = new LazyLogger{};
	}
	return *m_pInstance;
}

LazyLogger::~LazyLogger() {
	fclose(m_pStream);
}

void LazyLogger::WriteLog(const char* pMessage) {
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), pMessage); //maybe written in file buffer
	fflush(m_pStream); //ensure it is written to file
}

void LazyLogger::SetTag(const char* pTag) {
	m_Tag = pTag;
}
