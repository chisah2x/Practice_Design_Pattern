#pragma once
#include <ostream>

struct Position3D {
	int x,y,z ;

	friend std::ostream& operator<<(std::ostream& os, const Position3D& obj) {
		return os
			<< "(" << obj.x
			<< ", " << obj.y
			<< ", " << obj.z
			<<")\n" ;
	}
};
class Model
{
public:
	virtual void Render() ;
	virtual void Render(Position3D position) ;
	virtual ~Model() = default ;
};

