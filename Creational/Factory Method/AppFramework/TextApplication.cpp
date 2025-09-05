#include "TextApplication.h"
#include "TextDocument.h"
#include <iostream>

DocumentPtr TextApplication::Create()
{
	return std::make_unique<TextDocument>();

}
