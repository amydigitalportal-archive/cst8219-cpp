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

#pragma once
#include "../include/Vehicle.h"

using namespace std;
using namespace CST8219;

Vehicle::Vehicle(int w, int d) : numWheels(w), numDoors(d) 
{ 
}

/**
* Destructor.
*/
Vehicle::~Vehicle()
{
}

void Vehicle::SanitizeData()
{
	// Enforce: `numWheels`
	if (numWheels < 0) numWheels = 0;
	
	// Enforce: `numDoors`
	if (numDoors < 0) numDoors = 0;
}