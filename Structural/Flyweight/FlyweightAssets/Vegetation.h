#pragma once
#include <vector>
#include <string_view>

#include "Model.h"
class VegetationData {
	std::vector<int> m_MeshData{};
	const char* m_Texture{};
public:
	VegetationData() ;
	const char *GetTexture()const ;
	const std::vector<int> & GetMeshData()const ;
};
class Vegetation :
	public Model
{
	inline static int m_Count{};
	VegetationData *m_pVegData{} ;
	std::string m_Tint{};
public:
	Vegetation(std::string_view tint, VegetationData *p);
	void Render(Position3D position) override;
	static void ShowCount();
};

