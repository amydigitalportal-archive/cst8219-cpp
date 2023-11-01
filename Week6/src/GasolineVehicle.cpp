/*File: GasolineVehicle.cpp
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

#include "../include/GasolineVehicle.h"

using namespace std;
using namespace CST8219;

void GasolineVehicle::SanitizeData()
{
	Vehicle::SanitizeData();

	// Enforce: `maximumCharge`: Negative max?
	if (maximumGasoline < 0) maximumGasoline = 0;

	// Enforce: `currentCharge`
	currentGasoline =
		// Negative gas?
		(currentGasoline < 0) ? 0
		// Current exceed Max?
		: (currentGasoline > maximumGasoline) ? maximumGasoline
		// Good.
		: currentGasoline;
}

/* Should return */
float GasolineVehicle::CalculateRange()
{
	GasolineVehicle::SanitizeData();

	if (engineEfficiency == 0) // cheat codes!
	{
		return std::numeric_limits<float>::infinity();
	}

	if (currentGasoline == 0) // fill some gas!
	{
		return 0;
	}

	return (currentGasoline == 0) ? 0
		: currentGasoline * 100 / engineEfficiency;
}

float GasolineVehicle::PercentEnergyRemaining()
{
	return (currentGasoline / maximumGasoline) * 100.0f;
}

void GasolineVehicle::Drive(float km)
{
	currentGasoline -= (km / 100) * GasolineVehicle::engineEfficiency;
	if (currentGasoline <= 0)
	{
		currentGasoline = 0;
		std::cout << "Charge depleted! ...\n";
	}
}

GasolineVehicle::GasolineVehicle(float maximumGasoline, float engineEfficiency, int nWheels, int nDoors)
	: Vehicle::Vehicle(nWheels, nDoors)
{
	this->maximumGasoline = maximumGasoline;
	this->currentGasoline= maximumGasoline; // Fully charged.

	GasolineVehicle::engineEfficiency = engineEfficiency;

	this->SanitizeData();
}

GasolineVehicle::~GasolineVehicle()
{
	cout << "In 'GasolineVehicle' Destructor" << endl;
}