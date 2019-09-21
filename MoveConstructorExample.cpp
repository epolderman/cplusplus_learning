#include "pch.h"
#include "MoveConstructorExample.h"


/*
Copy constructor
First, let’s look at the good old copy constructor. Its purpose is, given an object, 
to create a second object that would be equal to the original; so that once the operation 
is done we have two objects with the same value. This operation is costly for types that 
require more memory than that reported by operator sizeof. Memory is not the only resource 
that makes copying expensive, but it is a good enough example for our purpose. Consider class 
template std::vector. Typically, the size of a vector (if measured with sizeof) would be that 
of three pointers, because three pointers are enough to represent a vector: one pointer indicates 
the beginning of memory allocated for vector, one pointer indicates the end of the memory piece, 
the third indicates what portion of this memory is really used by vector elements. Allocating and 
populating this memory took time. And now, if we want the second, new, vector to have the same value, 
we will have to allocate a similar chunk of memory, call copy constructors for each vector element,
which itself may require additional memory allocation. Such a deep copy may be expensive, but acceptable 
if you really require two objects with the same value. It becomes a problem, however, when you do not 
require two copies of the same object but you are still forced to use copy constructor.

https://akrzemi1.wordpress.com/2011/08/11/move-constructor/

http://definedbehavior.blogspot.com/2011/08/value-semantics-copy-elision.html
*/

MoveConstructorExample::MoveConstructorExample()
{
	cout << "Constructor" << endl;
}


MoveConstructorExample::~MoveConstructorExample()
{
	cout << "Destructor" << endl;
}
