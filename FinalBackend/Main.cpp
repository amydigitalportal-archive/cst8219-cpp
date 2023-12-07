#include "Test.h"


#include <iostream>
#include <format>

using namespace std;

/*-- MAIN */

int main()
{
    UniformTest uni(1000);
    cout << "[   Uniform distribution   ]" << endl;
    auto min = uni.GetMin(), max = uni.GetMax();
    cout << "- Min: " << min << " | Max: " << max << endl;
    auto range = max - min;
    cout << "- (Range of values: " << range << " )" << endl;
    auto bucketSize = range / NUM_BUCKETS;
    cout << "- Size of each bucket: " << bucketSize << endl;
    cout << "-----------------" << endl;

    std::vector<int> hist = uni.GetHistogram();
    int b = 1;
    for (int count : hist) {
        printf("[%-*d] : ", 2, b++); // Ref: https://stackoverflow.com/a/16119512
        for (int n = 0; n < count; n++) cout << "*";
        cout << endl;
    }

    return 0;
}