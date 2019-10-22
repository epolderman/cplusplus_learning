#include "pch.h"
#include "VectorExample.h"


VectorExample::VectorExample()
{
	cout << "VECTOR EXAMPLE->>>>>>" << endl;
	vector<int> one = { 1 ,2, 3, 4, 5 };
	print(one);

	vector<int> two(one);
	print(two);


	// Scott Meyers item 5 - 

	// range based assign
	vector<int> three;
	three.assign((two.begin() + two.size() / 2), two.end());
	print(three);

	// range based construction
	vector<int> four(three.begin(), three.end());
	print(four);

	// range based erase
	/*
		vector.end() = Returns an iterator referring to the past-the-end
		element in the vector container.The past-the-end element is the theoretical
		element that would follow the last element in the vector. It does not point to
		any element, and thus shall not be dereferenced.
	*/

	// single erase
	vector<int> five(one.begin(), one.end());
	vector<int>::iterator myPtr;
	myPtr = five.end() - 1;
	cout << *myPtr << endl;
	five.erase(myPtr);
	print(five);

	// range erase
	vector<int> six(one.begin(), one.end());
	vector<int>::iterator iter1, iter2;
	iter1 = six.begin();
	iter2 = six.end();
	iter1++;
	iter2--;
	six.erase(iter1, iter2);
	print(six);

	/*
		remove elements that are 5 / remove/erase idiom Scott Meyers:ITEM 32
		remove doesn't actually remove elements, it scans and re-assigns elements to the
		end of the container and returns an iterator to that index, erase then takes
		and index, and the end, and removes from the container
	*/
	vector<int> eight = { 1,2,3,4,4,4,4,4,5 };
	print(eight);
	eight.erase(std::remove(eight.begin(), eight.end(), 4), eight.end());
	print(eight);

	// range base insert
	vector<int> seven(one.begin(), one.end());
	vector<int>::iterator iter = six.begin();
	seven.insert(seven.end(), iter, six.end());
	print(seven);


	// how to remove vector/class object by inspecting without for loop
	vector3d veg;
	veg.x = 5;
	veg.y = 5;
	veg.z = 6;

	cout << veg.x << " " << veg.y << " " << veg.z << endl;
	vector<vector3d> tempVectorContainer = { veg };
	cout << tempVectorContainer.size() << endl;
	tempVectorContainer.push_back(vector3d());
	tempVectorContainer.push_back(vector3d());

	cout << "Size before remove if " << tempVectorContainer.size() << endl;
	vector3d vee;
	VectorMatcher matcher(vee);
	if (matcher(veg)) {
		cout << "Does Match" << endl;
	}
	else {
		cout << "Doesn't Match" << endl;
	}

	// remove if with predicate matcher ( anonymous functor VectorMatcher(vee) which is a functor )
	tempVectorContainer.erase(std::remove_if(tempVectorContainer.begin(), tempVectorContainer.end(), VectorMatcher(vee)), tempVectorContainer.end());
	cout << "Size after remove if " << tempVectorContainer.size() << endl;

	cout << "VECTOR EXAMPLE END->>>>>>" << endl;
}


VectorExample::~VectorExample()
{
}

void VectorExample::print(vector<int> &v)
{
	cout << "Printing " << v.size() << endl;
	vector<int>::iterator myPtr;
	for (myPtr = v.begin(); myPtr < v.end(); myPtr++) {
		cout << *myPtr << " ";
	}
	cout << endl;
}
