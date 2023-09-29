/*File: Week3.cpp
* 
* Course: CST8219 C++ Programming (23F)
* Section: 302
* Professor: Eric Torunski
* 
* Student: Amy Novun - 040 757 422
* 
* Assignment: Lab Week 3
* Due Date: 24 SEP 2023
*/

#include<iostream>
#include<climits>

using namespace std;

namespace CST8219 {

	class Vehicle
	{
	private:
		int numWheels, numDoors;

	public:
		Vehicle(int w, int d)
		{
			numWheels = w;
			numDoors = d;

			cout << "# DEBUG : In constructor with 2 parameters" << endl;
		}

		Vehicle(int w) : Vehicle(w, 4)
		{
			cout << "# DEBUG : In constructor with 1 parameters, wheels = " << w << endl;
		}

		Vehicle() : Vehicle(4)
		{
			cout << "# DEBUG : In constructor with 0 parameters" << endl;
		}

		~Vehicle()
		{
			cout << "# DEBUG : In destructor" << endl;
		}

		int GetNumWheels() { return numWheels; }
		int GetNumDoors() { return numDoors; }
	};
}

int GetNumberOf(string vehicleParts) {
	int num;
	do {
		cout << "Enter the number of " << vehicleParts << ": ";
		cin >> num;
		if (num <= 0) {
			cout << "# error - Invalid input. Please enter a number greater than 0." << endl;
			cin.clear(); cin.ignore(INT_MAX, '\n');
			continue;
		}
	} while (num <= 0);

	return num;
};

int main(int argc, char **argv)
{
	CST8219::Vehicle veh1;
	CST8219::Vehicle veh2(4);
	CST8219::Vehicle veh3(4, 2);

	cout << "Vehicle 1 takes " << sizeof(veh1) << endl;
	cout << "Vehicle 2 takes " << sizeof(veh2) << endl;
	cout << "Vehicle 3 takes " << sizeof(veh3) << endl;

	char userResponse;
	do {

		CST8219::Vehicle* pVehicle;

		int w = GetNumberOf("wheels");
		int d = GetNumberOf("doors");

		pVehicle = new CST8219::Vehicle(w, d);
		cout << "Vehicle has "
			<< pVehicle->GetNumWheels() << " wheels"
			<< " and "
			<< pVehicle->GetNumDoors() << " doors"
			<< "." << endl;

		delete pVehicle;

		cout << endl << "Enter a new vehicle? (To QUIT the program, type 'q' without the apostrophes): ";
		cin >> userResponse;

	} while (userResponse != 'q' && userResponse != 'Q');

	cout << endl << "Thank you for using this program!" << endl;

	return 0;
}