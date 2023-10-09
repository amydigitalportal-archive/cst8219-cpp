/*File: Vehicle.cpp
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

using namespace std;
using namespace CST8219;

//#define DEBUG_LOGGING

/*
* Prints out the specified message
* only when DEBUG_LOGGING is defined.
*/
void DebugLog(string msg) {
#ifdef DEBUG_LOGGING
	cout << msg << endl;
#endif // DEBUG_LOGGING
}

Vehicle::Vehicle(int w, int d) : numWheels(w), numDoors(d)
{
	DebugLog("In constructor with 2 parameters");
}

//Vehicle::Vehicle(int w) : Vehicle::Vehicle(w, 0)
//{
//	DebugLog("In constructor with 1 parameters, wheels = " + w);
//}

//Vehicle::Vehicle() : Vehicle(0)
//{
//	DebugLog("In constructor with 0 parameters");
//}

Vehicle::~Vehicle()
{
	DebugLog("In destructor");
}

/* -- "Copy Constructor" */
Vehicle::Vehicle(Vehicle& source) 
{
	numWheels = source.numWheels;
	numDoors = source.numDoors;
}

Vehicle::Vehicle(Vehicle* source) : Vehicle(*source)
{

}


void Vehicle::PrintVehicle(Vehicle &v) 
{
	cout << "Vehicle at address: " << &v << endl
		<< "Number of wheels: " << v.numWheels << endl
		<< "Number of doors: " << v.numDoors << endl
		<< endl;
}

void Vehicle::PrintVehicle() {
	PrintVehicle(*this);
}