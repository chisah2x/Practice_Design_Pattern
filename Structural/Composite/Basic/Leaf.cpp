#include "Leaf.h"

#include <iostream>

void Leaf::Add(Component* pComponent) {
}

Component* Leaf::GetChild(int index) {
	return nullptr ;
}

void Leaf::Operation() {
	std::cout << "[Left] Operation invoked" << std::endl;
}

void Leaf::Remove(Component* pComponent) {
}
