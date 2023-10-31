/*File: Vehicle.cpp
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

using namespace std;
using namespace CST8219;

//#define DEBUG_LOGGING
//#define USE_GETTERS

/*
* Prints out the specified message
* only when DEBUG_LOGGING is defined.
*/
void DebugLog(string msg) 
{
#ifdef DEBUG_LOGGING
	cout << msg << endl;
#endif // DEBUG_LOGGING
}

#ifdef USE_GETTERS
Vehicle::GetNumWheels()
{
	return numWheels;
}

Vehicle::GetNumDoors()
{
	return numDoors;
}
#endif // USE_GETTERS

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

void Vehicle::PrintVehicle() 
{
	PrintVehicle(*this);
}

Vehicle& Vehicle::operator=(const Vehicle& other) 
{
	if (this != &other) {
		numWheels = other.numWheels;
		numDoors = other.numDoors;
	}

	return *this;
}

bool Vehicle::operator==(const Vehicle& other) const 
{
	return (this->numWheels == other.numWheels)
		&& (this->numDoors == other.numDoors);
}

bool Vehicle::operator!=(const Vehicle& other) const 
{
	return ! operator==(other);
}

/* Pre-fix increment. */
Vehicle Vehicle::operator++() 
{
	numWheels++; numDoors++;
	return Vehicle(this);
}

/* Post-fix increment. */
Vehicle Vehicle::operator++(int i) 
{
	// return a copy of the original Vehicle before incrementing values for "this"
	Vehicle copy(numWheels, numDoors);
	this->operator++();
	return copy;

	/* Alternative. */
	//return Vehicle(this->numWheels++, this->numDoors++);
}

/* Pre-fix decrement. */
Vehicle Vehicle::operator--() 
{
	numWheels--; numDoors--;
	return Vehicle(this);
}

/* Post-fix decrement. */
Vehicle Vehicle::operator--(int i) 
{
	Vehicle copy(numWheels, numDoors);
	this->operator--();
	return copy;
}

ostream& CST8219::operator<<(ostream& os, const Vehicle& v)
{
	os << "Vehicle at address: " << &v << endl
		<< "Number of wheels: " << v.numWheels << endl
		<< "Number of doors: " << v.numDoors << endl
		<< endl;
	return os;
}