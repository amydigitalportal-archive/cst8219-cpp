/*File: Week2.cpp
* 
* Course: CST8219 C++ Programming (23F)
* Section: 302
* Professor: Eric Torunski
* 
* Student: Amy Novun - 040 757 422
* 
* Assignment: Lab 2
* Due Date: 24 SEP 2023
*/

#include<iostream>

using namespace std;

namespace CST8219 {
	class Vehicle;
}

class Vehicle
{
private:
	int numWheels, numDoors;

public:
	Vehicle(int w, int d) 
	{
		numWheels = w;
		numDoors = d;

		cout << "In constructor with 2 parameters" << endl;
	}

	Vehicle(int w) : Vehicle(w, 4)
	{
		cout << "In constructor with 1 parameters, wheels = " << w << endl;
	}

	Vehicle() : Vehicle(4) 
	{
		cout << "In constructor with 0 parameters" << endl;
	}

	~Vehicle() 
	{
		cout << "In destructor" << endl;
	}
};

int main(int argc, char **argv)
{
	cout << "Hello World!" << endl;
	return 0;
}