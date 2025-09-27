#pragma once
#include <ostream>
#include <unordered_map>
#include <boost/functional/hash.hpp>

namespace WithoutFlyweight{
class String
{
	inline static int count{} ;
	char *m_pBuffer{} ;
	size_t m_Length{} ;
	void Allocate(const char *pstr) ;
public:
	String() ;
	String(const char *pstr) ;
	~String() ;
	String(const String &other) ;
	String(String &&other)noexcept ;

	String & operator=(const String &other) ;
	String & operator=(String &&other)noexcept ;

	size_t GetLength()const ;
	const char *GetString()const ;

	void Assign(const char *pstr) ;
	void Assign(const String &other) ;
	static void ShowCount() ;
	friend std::ostream& operator<<(std::ostream& os, const String& obj) {
		return os << obj.m_pBuffer;
	}

	friend bool operator==(const String& lhs, const String& rhs) {
		return lhs.m_Length == rhs.m_Length
		&& strcmp(lhs.m_pBuffer, rhs.m_pBuffer) == 0;
	}

	friend bool operator!=(const String& lhs, const String& rhs) {
		return !(lhs == rhs);
	}

	friend std::size_t hash_value(const String& obj) {
		std::size_t seed = 0x47FB5D6E;
		boost::hash_combine(seed, obj.m_pBuffer);
		boost::hash_combine(seed, obj.m_Length);
		return seed;
	}
};

}

namespace WithFlyweight {
	struct StringInfo {
	char *m_pBuffer{} ;
	size_t m_Length{} ;
	size_t m_Count{} ;
	inline static int count{} ;
	StringInfo(const char *p) ;
	~StringInfo();
	static void ShowCount() ;
};
class String
{
	StringInfo *m_pCurrent{} ;
	inline static std::unordered_map<std::string_view, StringInfo*> m_Strings{} ;
	[[nodiscard]]
	StringInfo *Find(const char *p) ;
	void AddRef(StringInfo *pOther) ;
	void CreateNew(const char *p) ;
	void Release() ;
	inline static int count{} ;
public:
	static void ShowCount() ;
	String() =default ;
	String(const char *pstr) ;
	~String() ;
	String(const String &other) ;
	String(String &&other)noexcept ;

	String & operator=(const String &other) ;
	String & operator=(String &&other)noexcept ;

	size_t GetLength()const ;
	const char *GetString()const ;

	void Assign(const char *pstr) ;
	void Assign(const String &other) ;

	friend std::ostream& operator<<(std::ostream& os, const String& obj) {
		return os << obj.m_pCurrent->m_pBuffer;
	}
};
}