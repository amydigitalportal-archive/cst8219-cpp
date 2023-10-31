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

#include <iostream>

using namespace std;
using namespace CST8219;

/* -- Function prototypes. */
void CreateVehicle(Vehicle& v, int w, int d);
void RunWeek4();
void RunWeek5();
void RunWeek6();

#ifndef VEHICLE_IS_ABSTRACT
void CreateVehicle(Vehicle& v, int w = 4, int d = 2) {
	v = Vehicle(w, d);
}

void RunWeek4()
{
	// use empty constructor, no `()`
	Vehicle original;

	// use copy constructor by reference
	Vehicle copy(original);

	// use copy constructor by pointer/address of
	Vehicle secondCopy(&original);

	copy.PrintVehicle();		// expect: w = 0, d = 0
	CreateVehicle(copy, 2);
	copy.PrintVehicle();		// expect: w = 2, d = 0
	CreateVehicle(copy, 2, 3);
	copy.PrintVehicle();		// expect: w = 2, d = 3

	copy = secondCopy;
	copy.PrintVehicle();		// expect: w = 0, d = 0

	cout << endl;
}

void RunWeek5()
{
	Vehicle original;
	Vehicle copy(original); // copy constructor by reference

	cout << "Original is: " << original << " copy is: " << copy << endl;

	cout << "Increment original: " << original++ << endl;
	cout << "Increment copy:" << ++copy << endl;

	cout << "Decrement original:" << --original << endl;
	cout << "Decrement copy:" << copy-- << endl;

	// should be true :
	cout << "Compare equality 1: " << (original == copy) << endl;

	//should be false:
	cout << "Compare equality 2: " << (--original == ++copy) << endl;

	//should be true:
	cout << "Compare inequality: " << (original != copy) << endl;

	//This should make original = copy, and then return a Vehicle for output:
	cout << "Assignment operator: " << (original = copy) << endl;
}

void RunWeek5PersonalTests()
{
	// -- Test Task # 2
	Vehicle v1(0, 0);
	Vehicle v2(0, 0);
	Vehicle v3(0, 0);

	Vehicle v4(4, 6);

	v1 = v2 = v3 = v4;

	v1.PrintVehicle();
	v2.PrintVehicle();
	v3.PrintVehicle();
	v4.PrintVehicle();

	// -- Test Task # 3

	Vehicle v5(18, 2);
	v5.PrintVehicle();

	if (v2 == v5) {
		cout << "Vehicle #2 has the same number of wheels and doors as Vehicle #5!" << endl;
	}
	// -- Test Task # 4
	else if (v2 != v5) {
		cout << "Vehicle #2 and Vehicle #5 don't match!" << endl;
	}
	cout << endl << endl;

	// Task #5
	{
		// -- Test Task #5-a: ++v

		cout << "-- 5-a." << endl;

		Vehicle v1_copied = ++v1;
		cout << "Copy of v1's values returned PRE-increment ..." << endl;
		v1_copied.PrintVehicle();
		cout << "v1's values ..." << endl;
		v1.PrintVehicle();

		// -- Test Task #5-b: v++

		cout << "-- 5-b." << endl;
		Vehicle v2_copied = v2++;
		cout << "Copy of v2's values returned POST-increment ..." << endl;
		v2_copied.PrintVehicle();
		cout << "v2's values ..." << endl;
		v2.PrintVehicle();

		// -- Test Task #5-c: --v

		cout << "-- 5-c." << endl;
		Vehicle v3_copied = --v3;
		cout << "Copy of v3's values returned PRE-decrement ..." << endl;
		v3_copied.PrintVehicle();
		cout << "v3's values ..." << endl;
		v3.PrintVehicle();

		// -- Test Task #5-d: v--

		cout << "-- 5-d." << endl;
		Vehicle v4_copied = v4--;
		cout << "Copy of v4's values returned POST-decrement ..." << endl;
		v4_copied.PrintVehicle();
		cout << "v4's values ..." << endl;
		v4.PrintVehicle();

	}//end Task # 5

	// Test Task # 6
	cout << "-- Task # 6: Displaying Vehicle using ostream ..." << endl;
	Vehicle outputVeh(123, 456);
	cout << outputVeh << endl;
}
#endif

void RunTester()
{
	ElectricVehicle* ev = new ElectricVehicle(75, 16);

	float range = ev->CalculateRange();
	cout << "Initial range: " << range;

	ev->Drive(150);
	float range2 = ev->CalculateRange();
	cout << "New range: " << range2;
}

Vehicle* testVehicle(Vehicle* pVehicle, const char* vehicleName)
{
	cout << vehicleName << "'s range is: " << pVehicle->CalculateRange() << endl;
	cout << "Driving 150 km ..." << endl;
	pVehicle->Drive(150); //drive 150 km
	cout << vehicleName << "'s energy left is: " << pVehicle->PercentEnergyRemaining() << endl;
	cout << vehicleName << "'s range is now: " << pVehicle->CalculateRange() << endl;

	return pVehicle;
}

void RunWeek6()
{
	//50L of gas, 7.1 L/100km
	delete testVehicle(new GasolineVehicle(50, 7.1f), "Corolla");
	cout << endl;


	//75 kWh, 16 kWh/100km
	delete testVehicle(new ElectricVehicle(75, 16), "Tesla 3");
	cout << endl;
}

int main(int argc, char** argv)
{
	//RunTester();

#ifndef VEHICLE_IS_ABSTRACT
	//RunWeek4();
	//RunWeek5();
#endif

	RunWeek6();

	return 0;
}