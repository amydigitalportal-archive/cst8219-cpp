/*File: Week4.cpp
*
* Course:		CST8219 C++ Programming (23F)
* Section:		302
* Professor:	Eric Torunski
*
* Student:		Amy Novun - 040 757 422
*
* Assignment:	Lab Week 5
* Due Date:		15 OCT 2023
*/

#include "Vehicle.h"

#include <iostream>

using namespace std;
using namespace CST8219;

/* -- Function prototypes. */
void CreateVehicle(Vehicle& v, int w, int d);
void RunWeek4();
void RunWeek5();

void CreateVehicle(Vehicle& v, int w = 4, int d = 2) {
	v = Vehicle(w, d);
}

void RunWeek4()
{
	// use empty constructor, no `()`
	Vehicle original;

	// use copy constructor by reference
	Vehicle copy(original);

	// use copy constructor by pointer/address of
	Vehicle secondCopy(&original);

	copy.PrintVehicle();		// expect: w = 0, d = 0
	CreateVehicle(copy, 2);
	copy.PrintVehicle();		// expect: w = 2, d = 0
	CreateVehicle(copy, 2, 3);
	copy.PrintVehicle();		// expect: w = 2, d = 3

	copy = secondCopy;
	copy.PrintVehicle();		// expect: w = 0, d = 0

	cout << endl;
}

void RunWeek5()
{
	Vehicle v1(4, 6);

	Vehicle v2(0, 0);

	v2 = v1;

	v2.PrintVehicle();
}


int main(int argc, char** argv)
{
	//RunWeek4();

	RunWeek5();

	return 0;
}