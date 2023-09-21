// Week 1.cpp : Defines the entry point for the application.
// CST8219 - C++ Programming (23F)
// Student: Amy Novun - 040 757 422
// Date: Sep 14, 2023

#include "Week1.h"

#include <iostream>

//#define USING_NAMESPACES

#ifdef USING_NAMESPACES
using namespace std;
#pragma message("Enabled using namespace 'std'.")
#else
#pragma message("Disabled using namespaces 'std'.")
#endif

int main()
{
#ifdef USING_NAMESPACES
	cout << "Hello world! (using namespaces)" << endl;
#else
	std::cout << "Hello world! (not using namespaces)" << std::endl;
#endif
	return 0;
}
