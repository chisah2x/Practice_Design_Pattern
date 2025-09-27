#include <memory>
#include <vector>

#include "Vegetation.h"
#include "VegetationFactory.h"

int main() {
	std::vector<VegetationPtr> m_Trees{} ;
	VegetationData data{} ;
	VegetationFactory factory{&data} ;
	for(int i = 0 ; i < 15 ; ++i) {
		if(i<5) {
			m_Trees.push_back(factory.GetVegetation("Green")) ;
		}else if(i>=5 && i <=10) {
			m_Trees.push_back(factory.GetVegetation("Dark Green")) ;
		}else {
			m_Trees.push_back(factory.GetVegetation("Light Green")) ;
		}
	}
	for(int i = 0 ; i < m_Trees.size() ; ++i) {
		if(i < 5)
			m_Trees[i]->Render({i*10, i*10, i*10}) ;
		else if(i >=5 && i<=10)
			m_Trees[i]->Render({i+10, i+10, i+10}) ;
		else
			m_Trees[i]->Render({i*10+10, i*10+10, i*10+10}) ;
	}
	Vegetation::ShowCount() ;

	auto c1 = factory.GetCar({1,2,3,4}, "Car texture", {10, 10, 10}) ;
}
