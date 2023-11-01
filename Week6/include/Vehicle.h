/*File: Vehicle.h
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
#ifndef VEHICLE_H
#define VEHICLE_H

#define VEHICLE_IS_ABSTRACT

#include <iostream>

namespace CST8219 
{
	class Vehicle
	{
	private:
		int numWheels;
		int numDoors;

	protected:
		float engineEfficiency = 0.0f;
		virtual void SanitizeData();

	public:
		/* -- Base Constructor. */
		Vehicle(int wheels = 0, int doors = 0);

		/* -- Destructor. */
		virtual ~Vehicle();

		/* -- Main Functions */

		virtual float CalculateRange() = 0;
		virtual float PercentEnergyRemaining() = 0;
		virtual void Drive(float km) = 0;
	};
}

#endif

