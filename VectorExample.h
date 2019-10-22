#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "IteratorExample.h"
using std::cout;
using std::vector;
using std::iterator;
using std::endl;
/*

	Functor: https://stackoverflow.com/questions/356950/what-are-c-functors-and-their-uses

	Item 39 -> Scott Meyers
	Predicate Function = returns bool or something that can be implicitly converted to bool.
	Pure Function = return value depends only on its parameters.
	Predicate Class = A functor class whose operator() function is a predicate (i.e. returns true/false).

	Function Objects (Functors) are passed by value. Design function objects to be copied. Algorithms may make copies of
	functors and hold on to them for awhile before using them.

*/
struct vector3d {
	float x, y, z;
	vector3d(float x = 1.0, float y = 1.0, float z = 1.0) : x(x), y(y), z(z) {}
};

struct VectorMatcher {
	vector3d target;
	VectorMatcher(vector3d v) : target(v) {}

	// Needs to be pure & const. 
	bool operator()(const vector3d &in) const {
		return target.x == in.x && target.y == in.y && target.z == in.z;
	}
};

class VectorExample
{
public:
	VectorExample();
	~VectorExample();
	void print(vector<int> &v);
};

