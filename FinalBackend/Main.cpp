#include "Test.h"


#include <iostream>

using namespace std;

/*-- MAIN */

int main()
{
    //UniformTest uni(1000);
    NormalTest norm(100);
    norm.GetHistogram();

    return 0;
}