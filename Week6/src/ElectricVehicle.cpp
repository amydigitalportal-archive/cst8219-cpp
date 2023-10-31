/*File: ElectricVehicle.cpp
*
* Course:		CST8219 C++ Programming (23F)
* Section:		302
* Professor:	Eric Torunski
*
* Student:		Amy Novun - 040 757 422
*
* Assignment:	Lab Week 6
* Due Date:		15 OCT 2023
*/

#include "../include/ElectricVehicle.h"

using namespace std;
using namespace CST8219;

void ElectricVehicle::SanitizeData()
{
	Vehicle::SanitizeData();

	// Enforce: `maximumCharge`
	if (maximumCharge < 0) maximumCharge = 0;

	// Enforce: `currentCharge`
	currentCharge = (currentCharge < 0) ? 0
		: (currentCharge > maximumCharge) ? maximumCharge
		: currentCharge;
}