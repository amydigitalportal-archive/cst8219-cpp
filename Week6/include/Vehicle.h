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
		float engineEfficiency;

	public:
		/* -- Getters -- */
		int GetNumWheels();
		int GetNumDoors();

		/* -- Constructors: Default & Chained */
		//Vehicle();
		//Vehicle(int wheels);
		Vehicle(int wheels = 0, int doors = 0);
		~Vehicle();
		/* -- Constructors: Copiers */
		Vehicle(Vehicle&);
		Vehicle(Vehicle*);

		/* -- Main Functions */

		void PrintVehicle(Vehicle& v);
		void PrintVehicle(void);
		virtual float CalculateRange() = 0;
		virtual float PercentEnergyRemaining() = 0;
		virtual void Drive(float km) = 0;

		/* -- Operator overloads */

		Vehicle& operator=(const Vehicle& other);
		bool operator==(const Vehicle& other) const;
		bool operator!=(const Vehicle& other) const;

#ifndef VEHICLE_IS_ABSTRACT
		/* Artifacts from Week5; Disabled due to abstract class. */
		Vehicle operator++();
		Vehicle operator++(int i);
		Vehicle operator--();
		Vehicle operator--(int i);
#endif

		friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
	};
}

#endif

