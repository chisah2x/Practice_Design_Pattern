#include "String.h"

#include <iostream>
namespace WithoutFlyweight {

	void String::Allocate(const char* pstr) {
		m_Length = strlen(pstr);
		m_pBuffer = new char[m_Length + 1];
		strcpy_s(m_pBuffer, m_Length + 1, pstr);
	}

	String::String() {
		++count;
		m_pBuffer = new char[1]{ '\0' };
	}

	String::String(const char* pstr) {
		++count;
		Allocate(pstr);
	}

	String::~String() {
		--count;
		delete[]m_pBuffer;
	}

	String::String(const String& other) {
		++count;
		Allocate(other.m_pBuffer);
	}

	String::String(String&& other) noexcept {
		++count;
		m_Length = other.m_Length;
		m_pBuffer = other.m_pBuffer;

		other.m_Length = 0;
		other.m_pBuffer = nullptr;
	}

	String& String::operator=(const String& other) {
		Assign(other);
		return *this;
	}

	String& String::operator=(String&& other) noexcept {
		if (this != &other) {
			delete[]m_pBuffer;
			m_Length = other.m_Length;
			m_pBuffer = other.m_pBuffer;

			other.m_Length = 0;
			other.m_pBuffer = nullptr;
		}
		return *this;
	}

	size_t String::GetLength() const {
		return m_Length;
	}

	const char* String::GetString() const {
		return m_pBuffer;
	}

	void String::Assign(const char* pstr) {
		delete[]m_pBuffer;
		Allocate(pstr);
	}

	void String::Assign(const String& other) {
		if (this != &other) {
			Assign(other.m_pBuffer);
		}
	}

	void String::ShowCount() {
		std::cout << "[String] Instances:" << count << std::endl;
	}
}

namespace WithFlyweight {
	StringInfo::StringInfo(const char* p) {
		m_Length = strlen(p);
		m_pBuffer = new char[m_Length + 1];
		strcpy_s(m_pBuffer, m_Length + 1, p);
		++m_Count;
		++count;
	}

	StringInfo::~StringInfo() {
		delete[]m_pBuffer;
		--count;
	}

	void StringInfo::ShowCount() {
		std::cout << "[StringInfo] Instances :" << count << std::endl;
	}

	StringInfo* String::Find(const char* p) {
		if (auto pInfo = m_Strings.find(p); pInfo != end(m_Strings)) {
			return pInfo->second;
		}
		return nullptr;
	}

	void String::AddRef(StringInfo* pOther) {
		m_pCurrent = pOther;
		++m_pCurrent->m_Count;
	}

	void String::CreateNew(const char* p) {
		m_pCurrent = new StringInfo{ p };
		m_Strings[p] = m_pCurrent;
	}

	void String::Release() {
		if (m_pCurrent == nullptr)
			return;
		auto pInfo = m_Strings.find(m_pCurrent->m_pBuffer);
		if (--pInfo->second->m_Count == 0) {
			delete m_pCurrent;
			m_Strings.erase(pInfo);
		}
		m_pCurrent = nullptr;
	}

	void String::ShowCount() {
		std::cout << "[String] Instances :" << count << std::endl;
	}

	String::String(const char* p) {
		++count;
		if (auto* pInfo = Find(p); pInfo != nullptr) {
			AddRef(pInfo);
		}
		else {
			CreateNew(p);
		}
	}

	String::String(const String& other) {
		++count;
		m_pCurrent = other.m_pCurrent;
		++m_pCurrent->m_Count;
	}

	String::String(String&& other)noexcept {
		++count;
		m_pCurrent = other.m_pCurrent;
		other.m_pCurrent = nullptr;
	}

	String& String::operator=(String&& other)noexcept {
		if (this != &other) {
			Release();
			m_pCurrent = other.m_pCurrent;
			other.m_pCurrent = nullptr;
		}
		return *this;
	}

	String& String::operator=(const String& other) {
		if (this != &other) {
			Release();
			m_pCurrent = other.m_pCurrent;
			if (m_pCurrent)
				++m_pCurrent->m_Count;
		}
		return *this;
	}

	size_t String::GetLength() const {
		if (m_pCurrent == nullptr)
			return 0;
		return m_pCurrent->m_Length;
	}

	const char* String::GetString() const {
		if (m_pCurrent == nullptr)
			return "";
		return m_pCurrent->m_pBuffer;
	}

	void String::Assign(const char* p) {
		if (strcmp(p, m_pCurrent->m_pBuffer) == 0)
			return;
		if (auto pInfo = Find(p); pInfo != nullptr) {
			Release();
			AddRef(pInfo);
		}
		else {
			CreateNew(p);
		}
	}

	void String::Assign(const String& other) {
		if (this == &other) {
			return;
		}
		Release();
		m_pCurrent = other.m_pCurrent;
		if (m_pCurrent)
			++m_pCurrent->m_Count;
	}

	String::~String() {
		--count ;
		Release();
	}

}