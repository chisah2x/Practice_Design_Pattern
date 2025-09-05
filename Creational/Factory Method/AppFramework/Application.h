#pragma once
#include <memory>
#include "Document.h"

using DocumentPtr = std::unique_ptr<Document>;

class Application
{
	//Document *m_pDocument ;
	DocumentPtr m_pDocument;
public:
	void New() ;
	void Open() ;
	void Save() ;
	virtual DocumentPtr Create() { return nullptr; }
};

