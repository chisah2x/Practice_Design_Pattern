#pragma once
#include <vector>
#include <string_view>

#include "Model.h"
class Vegetation :
    public Model
{
	inline static int m_Count{} ;
	std::vector<int> m_MeshData{} ;
	const char *m_Texture{} ;
	std::string m_Tint{} ;
	Position3D m_Position{} ;
public:
	Vegetation(std::string_view tint, Position3D position ) ;
	void Render() override;
	static void ShowCount() ;
};

