#include "Composite.h"
#include "Leaf.h"

int main() {
	Leaf leaf1, leaf2, leaf3 ;
	Composite root ;
	root.Add(&leaf1) ;
	root.Add(&leaf2) ;

	Composite subRoot1{}, subRoot2{} ;
	subRoot1.Add(&leaf1) ;
	subRoot2.Add(&leaf2) ;

	root.Add(&subRoot1) ;
	//root.Add(&subRoot2) ;
	
	root.Operation() ;
}

/*
 *	root
 *	|
 *	|-leaf1
 *	|-leaf2
 *	|
 *	|-subroot
 *	    |-leaf3
 * 
 */
