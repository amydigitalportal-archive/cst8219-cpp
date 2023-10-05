/*File: Week4.cpp
*
* Course:		CST8219 C++ Programming (23F)
* Section:		302
* Professor:	Eric Torunski
*
* Student:		Amy Novun - 040 757 422
*
* Assignment:	Lab Week 4
* Due Date:		6 OCT 2023
*/

#include "Vehicle.h"

#include <iostream>

using namespace std;
using namespace CST8219;

void CreateVehicle(Vehicle& v, int w = 4, int d = 2) {
	v = Vehicle(w, d);
}

int main(int argc, char** argv)
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

	return 0;
}