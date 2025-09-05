#include "TextApplication.h"
#include "SpreadSheetApplication.h"

int main() {
	TextApplication app;
	app.New() ;
	app.Open() ;
	app.Save() ;

	SpreadSheetApplication app2;
	app2.New();
	app2.Open();
	app2.Save();
	return 0;
}
