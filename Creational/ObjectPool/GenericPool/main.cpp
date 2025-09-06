#include "ObjectPool.h"
class Test {
	Test() {
		
	}
public:
	void Foo() {
		
	}
	friend class TestAllocator ;
};
class TestAllocator {
	public:
	Test * operator()() {
		return new Test{} ;
	}
	void operator()(Test *p) {
		delete p ;
	}
	void Reset() {
		
	}
};

//Todo: make it thread safe
int main() {
	using IntPool = ObjectPool<int> ;//Default size and allocator
	using TestPool = ObjectPool<Test, 2, TestAllocator> ;
	auto p1 = IntPool::Acquire() ;
	IntPool::Acquire() ;  
	//[[nodiscard]] is a C++ attribute that tells the compiler to warn you if the return value of a function is ignored.
	auto p3 = IntPool::Acquire() ;

	IntPool::Release(p1) ;

	auto p4 = IntPool::Acquire() ;
	IntPool::Destroy() ;
}
