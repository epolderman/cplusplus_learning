
#include "pch.h"
#include <iostream>
#include <vector>
#include <iterator>
#include "MoveConstructorExample.h"
using std::cout;
using std::vector;
using std::iterator;


void print(vector<int> v) {
	cout << "Printing " << v.size() << endl;
	vector<int>::iterator myPtr;
	for (myPtr = v.begin(); myPtr < v.end(); myPtr++) {
		cout << *myPtr << " ";
	}
	cout << endl;
}

int main()
{
	MoveConstructorExample mC;

	// iterators (random access for vectors // generalization over pointers)
	vector<int> v= { 1, 2, 3 };
	vector<int>::iterator myPtr;
	print(v);

	vector<int> one = { 1 ,2, 3, 4,5 };
	print(one);

	vector<int> two(one);
	print(two);



	return 0;
}
