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

	// Enforce: `maximumCharge`
	if (maximumGasoline < 0) maximumGasoline = 0;

	// Enforce: `currentCharge`
	currentGasoline = (currentCharge < 0) ? 0
		: (currentGasoline > maximumGasoline) ? maximumGasoline
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