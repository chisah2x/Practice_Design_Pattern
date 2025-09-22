#include "Button.h"
#include "Frame.h"

//void Display(Widget* pWidget)
//{
//	//pWidget->Paint();
//	if (auto pFrame = pWidget->GetParent(); pFrame != nullptr)
//	{
//		pWidget->AddChild(new Button{});
//	}
//	else
//	{
//		std::cout << "Cannot add a child" << std::endl;
//	}
//
//	if (auto pFrame = pWidget->GetParent(); pFrame != nullptr)
//	{
//		pFrame->Paint();
//	}
//	else {
//		std::cout << "No Parent\n";
//	}
//}

int main() {
	Frame mainWindow{} ;
	Button btnOk ;
	mainWindow.AddChild(&btnOk) ;
	mainWindow.Paint() ;

	//auto p = mainWindow.GetFrame() ;
	//if(p) {
	//	p->AddChild(&btnOk) ;
	//}
	//mainWindow.Paint() ;
	auto parent = btnOk.GetParent() ;
	parent->Paint() ;
	
}
