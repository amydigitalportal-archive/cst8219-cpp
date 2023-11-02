/*File: HybridVehicle.cpp
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

#include "../include/HybridVehicle.h"

#include <algorithm>

using namespace std;
using namespace CST8219;

float HybridVehicle::CalculateRange()
{
	float totalRange = ElectricVehicle::CalculateRange() + GasolineVehicle::CalculateRange();
	return totalRange;
}

float HybridVehicle::PercentEnergyRemaining()
{
	float percentElectric = ElectricVehicle::PercentEnergyRemaining();
	float percentGasoline = GasolineVehicle::PercentEnergyRemaining();
	return (percentElectric + percentGasoline) / 2;
}

void HybridVehicle::Drive(float km)
{
	if (km <= 0) {
		// "You're goin NO WHERRRRE" - Bonesaw McGraw, Spiderman (2002)
		return;
	}

	float distanceToDrive = km;

	// Calculate range of Electric
	float rangeElectric = ElectricVehicle::CalculateRange();
	// Do we have any range with Electric?
	if (rangeElectric > 0)
	{
		// Is target distance is longer than what Electric can get to?
		distanceToDrive -= (km > rangeElectric) ? 
			// Use up all the Electric range
			rangeElectric
			// Otherwise, drive the entire target-distance.
			: km;
		ElectricVehicle::Drive(distanceToDrive);
	}

	// Do we still have some distance to go?
	if (distanceToDrive > 0) 
	{
		// Calculate range of Gasoline
		float rangeGasoline = GasolineVehicle::CalculateRange();
		// Do we have any range with Gasoline?
		if (rangeGasoline > 0)
		{
			// Is remaining distance longer than what Gasoline can get to?
			distanceToDrive = (distanceToDrive > rangeGasoline) ?
				// Use up all the Gasoline range
				rangeGasoline
				// Otherwise, drive the entire remaining distance.
				: distanceToDrive;
			GasolineVehicle::Drive(distanceToDrive);
		}
	}
}

HybridVehicle::HybridVehicle(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float electricEfficiency, int nWheels, int nDoors)
	: ElectricVehicle(maximumCharge, electricEfficiency, nWheels, nDoors),  // Call ElectricVehicle constructor
	GasolineVehicle(maximumGasoline, gasolineEfficiency, nWheels, nDoors) // Call GasolineVehicle constructor
{
	// EV and GV constructors will handle their own data sanitizations.
}

HybridVehicle::~HybridVehicle()
{
	cout << "In 'HybridVehicle' Destructor" << endl;
}