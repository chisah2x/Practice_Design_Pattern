#include "SpreadSheetApplication.h"
#include "SpreadSheerDocument.h"
#include <iostream>


DocumentPtr SpreadSheetApplication::Create()
{
	return std::make_unique<SpreadSheerDocument>();
}
