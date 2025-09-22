#include "SharedString.h"

void SharedString::RemoveString() {
	auto found = m_Strings.find(m_pString);
	if (found != m_Strings.end()) {
		if (--(*found->second) == 0) {	
			delete m_pString;
			auto pCount = found->second;
			delete pCount;
			m_Strings.erase(found);

		}
	}
}



SharedString::SharedString(const char* pstr) {
	auto found = std::find_if(begin(m_Strings), end(m_Strings), [pstr](auto p) {
		return *p.first == pstr;
	});
	if (found != m_Strings.end()) {
		++(*found->second);
		m_pString = found->first;
	}
	else {
		String* pTemp = new String{ pstr };
		m_Strings[pTemp] = new size_t{ 1 };
		m_pString = pTemp;
	}
}

SharedString::SharedString(const SharedString& other) {
	if (!other.m_pString)
		return;
	auto found = m_Strings.find(other.m_pString);
	if (found != m_Strings.end()) {
		m_pString = other.m_pString;
		++(*found->second);
	}
}

SharedString::SharedString(SharedString&& other) noexcept {
	m_pString = other.m_pString;
	other.m_pString = nullptr;

}

SharedString& SharedString::operator=(const SharedString& other) {
	if (this != &other) {
		if (m_pString) {
			RemoveString();
		}
		auto found = m_Strings.find(other.m_pString);
		if (found != m_Strings.end()) {
			m_pString = other.m_pString;
			++(*found->second);
		}

	}
	return *this;
}

SharedString& SharedString::operator=(SharedString&& other) noexcept {
	if (this != &other) {
		if (m_pString) {
			RemoveString();
		}
		m_pString = other.m_pString;
		other.m_pString = nullptr;
	}
	return *this;
}

SharedString::~SharedString() {
	if (m_pString)
		RemoveString();
}

size_t SharedString::GetLength() const {
	if (!m_pString)
		return 0;
	return m_pString->GetLength();
}

const char* SharedString::GetString() const {
	if (!m_pString)
		return "";
	return m_pString->GetString();
}

void SharedString::Assign(const char* pstr) {
	if (m_pString) {
		RemoveString();
	}
	auto found = std::find_if(begin(m_Strings), end(m_Strings), [pstr](auto p) {
		return *p.first == pstr;
	});
	if (found != m_Strings.end()) {
		++(*found->second);
		m_pString = found->first;
	}
	else {
		String* pTemp = new String{ pstr };
		m_Strings[pTemp] = new size_t{ 1 };
		m_pString = pTemp;
	}
}

