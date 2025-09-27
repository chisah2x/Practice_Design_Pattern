#pragma once
#include <memory>
#include <unordered_map>

#include "Car.h"
class Model ;
class Vegetation ;
class VegetationData ;
using VegetationPtr = std::shared_ptr<Model> ;
class VegetationFactory
{
	std::unordered_map<std::string_view, VegetationPtr> m_Flyweights{} ;
	VegetationData *m_pVegData{} ;
public:

	VegetationFactory(VegetationData* mPVegData)
		: m_pVegData{mPVegData} {
	}
	VegetationPtr GetVegetation(std::string_view tint) ;
	std::shared_ptr<Car> GetCar(const std::vector<int>& mMeshData, const char* mPTexture, const Position3D& mPosition) ;
};

