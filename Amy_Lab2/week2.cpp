/*File: Week2.cpp
* 
* Course: CST8219 C++ Programming (23F)
* Section: 302
* Professor: Eric Torunski
* 
* Student: Amy Novun - 040 757 422
* 
* Assignment: Lab 2
* Due Date: 24 SEP 2023
*/

#include<iostream>

using namespace std;

class MyFirstClass 
{ 
private:
	int m_age;
	char *m_pFirstName, *m_pLastName;

protected:
	void setFirstName(char* f) { m_pFirstName = f; }
	void setLastName(char* l) { m_pLastName = l; }

public:
	MyFirstClass() : MyFirstClass(0, nullptr, nullptr) { }
	MyFirstClass(int age, char* firstName, char* lastName)
	{
		m_age = age;
		m_pFirstName = firstName;
		m_pLastName = lastName;
	}
};

class MySecondClass { };

int main(int argc, char **argv)
{
	MyFirstClass mfc;
	cout << "Hello World!" << endl;
	return 0;
}