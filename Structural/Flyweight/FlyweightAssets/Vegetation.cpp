#include "Vegetation.h"

#include <iostream>

Vegetation::Vegetation(std::string_view tint, VegetationData *p):m_Tint{tint}, m_pVegData{p}{
	++m_Count ;
	
}

void Vegetation::Render(Position3D position) {
	std::cout << m_pVegData->GetTexture() ;
	std::cout << "Mesh: " ;
	for(auto m : m_pVegData->GetMeshData()) {
		std::cout << m << ' ';
	}
	std::cout << "\nTint : " << m_Tint << std::endl ;
	std::cout << "Position : " << position << std::endl ;
}

VegetationData::VegetationData() {
	m_MeshData.assign({5,1,2,8,2,9}) ;
	m_Texture = R"(
    #
   ###
  #####
 #######
#########
    #
    #
)" ;
}

const char* VegetationData::GetTexture() const {
	return m_Texture ;
}

const std::vector<int>& VegetationData::GetMeshData() const {
	return m_MeshData ;
}

void Vegetation::ShowCount() {
	std::cout <<"Total objects created:" << m_Count << std::endl; 
}
