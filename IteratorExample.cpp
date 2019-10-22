#include "pch.h"
#include "IteratorExample.h"


IteratorExample::IteratorExample()
{
	cout << "ITERATOR EXAMPLE->>>>>>" << endl;
	vector<int> eight = { 1,2,3,4,4,4,4,4,5 };
	this->print(eight);
	eight.erase(std::remove(eight.begin(), eight.end(), 4), eight.end());
	print(eight);

	typedef vector<int> intVec;
	typedef intVec::iterator vectorIterator;

	vectorIterator vez = eight.begin();
	vectorIterator bez = eight.end();
	if (vez == bez) {
		cout << "Match-->" << endl;
		cout << *vez << endl;
		cout << *bez << endl;
	}
	else {
		bez = eight.end() - 1;
		cout << "No Match-->" << endl;
		cout << *vez << endl;
		cout << *bez << endl;
	}

	// iterators (random access for vectors // generalization over pointers)
	vector<int> v = { 1, 2, 3 };
	print(v);

	vector<int> one = { 1 ,2, 3, 4, 5 };
	print(one);

	vector<int> two(one);
	print(two);

	cout << "ITERATOR EXAMPLE END->>>>>>" << endl;
}


IteratorExample::~IteratorExample()
{
}

void IteratorExample::print(vector<int> &v)
{
	cout << "Printing " << v.size() << endl;
	vector<int>::iterator myPtr;
	for (myPtr = v.begin(); myPtr < v.end(); myPtr++) {
		cout << *myPtr << " ";
	}
	cout << endl;
}
