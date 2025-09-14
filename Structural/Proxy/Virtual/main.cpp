#include "Bitmap.h"
#include "BitmapProxy.h"

int main() {
	Image * img = new BitmapProxy{ "banner.txt" };
	img->Load();
	//img->Display();
	img->Load("Smiley.txt");
	img->Display();
	delete img;
}
