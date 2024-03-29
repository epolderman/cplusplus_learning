#include "pch.h"
#include "IteratorExample.h"

/*
	iterator pros: can insert and remove from containers without manually shifting contents.
	item 26: Prefer iterator to const_iterator, reverse_iterator, and const_reverse_iterator
	**This item has changed since C++11, now containers have const iterators cbegin,cend and
	most of the insertions and erases now accept const iterators
	- Most containers in the STL demand parameters to be of type iterator, not const iterator. (Not true anymore)

	item 27: Use distance and advance to convert a containers const_iterators to iterators.

	- ....

*/

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
	vector<int> two(one);

	vectorIterator i;
	for (i = two.begin(); i != two.end(); ++i) {
		if (i == two.begin()) {
			i = two.insert(i, 10);
		}
	}
	cout << "After Insertion:" << endl;
	print(two);

	// use const iterators > iterators since c++11
	using someAlistBrah = vector<int>::const_iterator;
	someAlistBrah constIterator = two.cbegin();
	someAlistBrah endConstIterator = two.cend();
	vector<int> myVector(constIterator, endConstIterator);

	print(myVector);
	const auto it = std::remove_if(myVector.begin(), myVector.end(), [](const int v) {return v == 10; });
	myVector.erase(it, myVector.end());
	print(myVector);


	

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
