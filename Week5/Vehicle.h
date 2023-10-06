/*File: Vehicle.h
*
* Course:		CST8219 C++ Programming (23F)
* Section:		302
* Professor:	Eric Torunski
*
* Student:		Amy Novun - 040 757 422
*
* Assignment:	Lab Week 5
* Due Date:		15 OCT 2023
*/

#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

namespace CST8219 
{
	class Vehicle
	{
	private:
		int numWheels;
		int numDoors;

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

		void PrintVehicle(Vehicle &v);
		void PrintVehicle(void);

		Vehicle& operator=(const Vehicle& other);
	};
}
#endif

