#include <memory>
#include <vector>

#include "Vegetation.h"

int main() {
	std::vector<std::shared_ptr<Vegetation>> m_Trees{} ;
	for(int i = 0 ; i < 15 ; ++i) {
		if(i<5) {
			m_Trees.push_back(std::make_shared<Vegetation>("Green", Position3D{i*10, i*10, i*10})) ;
		}else if(i>=5 && i <=10) {
			m_Trees.push_back(std::make_shared<Vegetation>("Dark Green", Position3D{i+10, i+10, i+10})) ;
		}else {
			m_Trees.push_back(std::make_shared<Vegetation>("Light Green", Position3D{i*10+10, i*10+10, i*10+10})) ;
		}
	}
	for(auto tree : m_Trees) {
		tree->Render() ;
	}
	Vegetation::ShowCount() ;
}
