/*File: ElectricVehicle.h
*
* Course:		CST8219 C++ Programming (23F)
* Section:		302
* Professor:	Eric Torunski
*
* Student:		Amy Novun - 040 757 422
*
* Assignment:	Lab Week 6
* Due Date:		03 NOV 2023
*/

#pragma once
#ifndef ELECTRIC_VEHICLE_H
#define ELECTRIC_VEHICLE_H

#include "Vehicle.h"

namespace CST8219
{
	class ElectricVehicle : public CST8219::Vehicle
	{
	protected:
		float currentCharge;
		float maximumCharge;

		void SanitizeData() override;

	public:
		float CalculateRange() override;
		float PercentEnergyRemaining() override;
		void Drive(float km) override;
	};
}

#endif