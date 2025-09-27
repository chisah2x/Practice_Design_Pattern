#include "VegetationFactory.h"
#include "Vegetation.h"
VegetationPtr VegetationFactory::GetVegetation(std::string_view tint) {
	auto found = m_Flyweights.find(tint) != end(m_Flyweights) ;
	if(!found) {
		m_Flyweights[tint] = std::make_shared<Vegetation>(tint, m_pVegData) ;
	}
	return m_Flyweights[tint] ;
}

std::shared_ptr<Car> VegetationFactory::GetCar(const std::vector<int>& mMeshData, const char* mPTexture,
	const Position3D& mPosition) {
	return std::make_shared<Car>(mMeshData, mPTexture, mPosition) ;
}
