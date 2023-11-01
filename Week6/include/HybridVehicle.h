/*File: HybridVehicle.h
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
#ifndef HYBRID_VEHICLE_H
#define HYBRID_VEHICLE_H

#include "ElectricVehicle.h"
#include "GasolineVehicle.h"

namespace CST8219
{
	class HybridVehicle : public ElectricVehicle, public GasolineVehicle
	{
	public:
		float CalculateRange() override;
		float PercentEnergyRemaining() override;
		void Drive(float km) override;

		HybridVehicle(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float electricEfficiency, int nWheels = 4, int nDoors = 4);
		virtual ~HybridVehicle();
	};
}

#endif