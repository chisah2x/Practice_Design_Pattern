#pragma once
#include <vector>

#include "Model.h"
class Car :
    public Model
{
	std::vector<int> m_MeshData{} ;
	const char *m_pTexture{} ;
	Position3D m_Position{} ;

public:
	Car(const std::vector<int>& mMeshData, const char* mPTexture, const Position3D& mPosition)
		: m_MeshData{mMeshData},
		  m_pTexture{mPTexture},
		  m_Position{mPosition} {
	}
	void Render() override;
};

