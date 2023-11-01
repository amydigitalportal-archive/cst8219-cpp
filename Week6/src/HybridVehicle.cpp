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
	// Calculate range before driving Electric.
	float rangeElectric = ElectricVehicle::CalculateRange();

	// Travel, then calculate distance traveled
	ElectricVehicle::Drive(km);
	// Recalculate range in case Vehicle somehow gained charge.
	rangeElectric = ElectricVehicle::CalculateRange();

	// Is Electric range shorter than target distance?
	if (rangeElectric < km)
	{
		// -- Calculate remaining distance.
		float remainingDistance = km - rangeElectric;
		// Drive using Gasoline.
		GasolineVehicle::Drive(remainingDistance);
	}

	// Check if Vehicle has depleted all fuel.
		/*if (HybridVehicle::PercentEnergyRemaining() <= 0.0)*/
	if (HybridVehicle::PercentEnergyRemaining() < 0.0)	// <- Assignment specifies "less than 0"
	{
		std::cout << "Your vehicle is out of energy!\n";

		ElectricVehicle::SanitizeData();
		GasolineVehicle::SanitizeData();
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