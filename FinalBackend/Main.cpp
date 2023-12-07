#include "Test.h"

#include <iostream>
#include <format>

//#define UNI
//#define NORM

using namespace std;

/*-- MAIN */

int main()
{
#ifdef UNI
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
#endif
#ifdef NORM
    NormalTest norm(10);
    cout << "[   Normal distribution   ]" << endl;
    auto min = norm.GetMin(), max = norm.GetMax();
    cout << "- Min: " << min << " | Max: " << max << endl;
    auto range = max - min;
    cout << "- (Range of values: " << range << " )" << endl;
    auto bucketSize = range / NUM_BUCKETS;
    cout << "- Size of each bucket: " << bucketSize << endl;
    cout << "-----------------" << endl;

    std::vector<double> hist = norm.GetHistogram();
    int b = 1;
    for (double count : hist) {
        printf("[%-*d] : ", 2, b++); // Ref: https://stackoverflow.com/a/16119512
        for (int n = 0; n < count; n++) cout << "*";
        cout << endl;
    }
#endif

    int numSamples = 1000;
    UniformTest<int> *test = new UniformTest<int>(numSamples);
    //NormalTest<double> *test = new NormalTest<double>(numSamples);

    cout << "[   Uniform distribution   ]" << endl;
    auto min = test->GetMin(), max = test->GetMax();
    cout << "- Min: " << min << " | Max: " << max << endl;
    auto range = max - min;
    cout << "- (Range of values: " << range << " )" << endl;
    auto bucketSize = range / NUM_BUCKETS;
    cout << "- Size of each bucket: " << bucketSize << endl;
    cout << "-----------------" << endl;

    auto hist = test->GetHistogram();
    int b = 1;
    for (auto count : hist) {
        printf("[%-*d] : ", 2, b++); // Ref: https://stackoverflow.com/a/16119512
        for (int n = 0; n < count; n++) cout << "*";
        cout << endl;
    }

    return 0;
}