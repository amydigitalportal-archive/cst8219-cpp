/*File: GasolineVehicle.h
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
#ifndef GASOLINE_VEHICLE_H
#define GASOLINE_VEHICLE_H

#include "Vehicle.h"

namespace CST8219
{
	class GasolineVehicle : public CST8219::Vehicle
	{
	protected:
		float	currentGasoline;
		float	maximumGasoline;

		void	SanitizeData() override;
	public:
		float	CalculateRange() override;
		float	PercentEnergyRemaining() override;
		void	Drive(float km) override;

		GasolineVehicle(float maximumGasoline, float engineEfficiency, int nWheels = 4, int nDoors = 4);
		virtual ~GasolineVehicle();
	};
}

#endif