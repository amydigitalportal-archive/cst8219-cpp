/*File: Week6.cpp
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

#include "../include/ElectricVehicle.h"
#include "../include/GasolineVehicle.h"
#include "../include/HybridVehicle.h"

#include <iostream>

using namespace std;
using namespace CST8219;

Vehicle* testVehicle(Vehicle* pVehicle, const char* vehicleName)
{
	cout << vehicleName << "'s range is: " << pVehicle->CalculateRange() << endl;
	cout << "Driving 150 km ..." << endl;
	pVehicle->Drive(150); //drive 150 km
	cout << vehicleName << "'s energy left is: " << pVehicle->PercentEnergyRemaining() << endl;
	cout << vehicleName << "'s range is now: " << pVehicle->CalculateRange() << endl;

	return pVehicle;
}

int main(int argc, char** argv)
{
	//50L of gas, 7.1 L/100km
	delete testVehicle(new GasolineVehicle(50, 7.1f), "Corolla");
	cout << endl;

	//42 L of gas, 4.3 L/100km, 8.8kWh, 22 kWh/100km
	delete testVehicle(dynamic_cast<ElectricVehicle*>(new HybridVehicle(42.0f, 4.3f, 8.8f, 22.0f)), "Prius");
	cout << endl;

	//75 kWh, 16 kWh/100km
	delete testVehicle(new ElectricVehicle(75, 16), "Tesla 3");
	cout << endl;

	return 0;
}