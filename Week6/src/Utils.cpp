
#include <iostream>

using namespace std;

//#define DEBUG_LOGGING

/*
* Prints out the specified message
* only when DEBUG_LOGGING is defined.
*/
void DebugLog(string msg)
{
#ifdef DEBUG_LOGGING
	cout << msg << endl;
#endif // DEBUG_LOGGING
}