#pragma once
#include <vector>
#include <iostream>
template<typename T>
class DefaultAllocator2 {
public:
	T* operator()() {
		return new T{};
	}
	void operator()(T* p) {
		delete p;
	}
	void Reset() {

	}
};
template<typename T, typename AllocatorT = DefaultAllocator2<T>>
class GrowableObjectPool
{
	struct ObjectInfo {
		bool m_IsUsed{};
		T* m_pObject{};
	};
	inline static std::vector<ObjectInfo> m_PooledObjects{};
	inline static AllocatorT m_Allocator{};
public:
	[[nodiscard("Object will remain unused")]]
	static T* Acquire() {
		for (auto& obj : m_PooledObjects) {
			if (!obj.m_IsUsed) {
				obj.m_IsUsed = true;
				std::cout << "[POOL] Returning an existing object\n";
				return obj.m_pObject;
			}
		}
		std::cout << "[POOL] Creating a new object\n";
		auto pObj = m_Allocator();
		m_PooledObjects.push_back({ true,pObj });
		return pObj;
	}
	static void Release(const T* pObj) {
		for (auto& obj : m_PooledObjects) {
			if (obj.m_pObject == pObj) {
				obj.m_IsUsed = false;
				break;
			}
		}
	}
	static void Destroy() {
		for (auto& obj : m_PooledObjects) {
			if (obj.m_IsUsed) {
				std::cout << "WARNING! Deleting an object still in use\n";
			}
			m_Allocator(obj.m_pObject);
		}
		m_Allocator.Reset();
		m_PooledObjects.clear();
	}
};

//class Test {
//	Test() {
//
//	}
//public:
//	void Foo() {
//
//	}
//	friend class TestAllocator;
//};
//class TestAllocator {
//public:
//	Test* operator()() {
//		return new Test{};
//	}
//	void operator()(Test* p) {
//		delete p;
//	}
//	void Reset() {
//
//	}
//};
//int main() {
//	using IntPool = GrowableObjectPool<Test, TestAllocator>;
//	auto p1 = IntPool::Acquire();
//	IntPool::Acquire();
//	//[[nodiscard]] is a C++ attribute that tells the compiler to warn you if the return value of a function is ignored.
//	auto p3 = IntPool::Acquire();
//
//	IntPool::Release(p1);
//
//	auto p4 = IntPool::Acquire();
//	IntPool::Destroy();
//}
