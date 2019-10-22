#pragma once

/* Class to handle iterator examples */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout;
using std::vector;
using std::iterator;
using std::endl;

class IteratorExample
{
public:
	IteratorExample();
	~IteratorExample();
	void print(vector<int> &v);
};

