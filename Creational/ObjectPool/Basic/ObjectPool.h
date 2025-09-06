
#pragma once
#include <vector>
#include <memory>
#include "SharedObject.h"

using SharedObjectPtr = std::shared_ptr<SharedObject>;

class ObjectPool
{
	ObjectPool() = default;
	inline static std::vector<SharedObjectPtr> m_PooledObjects{};
public:
	static SharedObjectPtr AcquireObject();
	static void ReleaseObject(SharedObjectPtr pSO);
};

//#pragma once
//#include <vector>
//class SharedObject;
//
//class ObjectPool
//{
//	ObjectPool() = default ;
//	inline static std::vector<SharedObject*> m_PooledObjects{} ;
//public:
//	static SharedObject * AcquireObject() ;
//	static void ReleaseObject(SharedObject *pSO) ;
//};