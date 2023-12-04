#include "TestRunner.h"

#include <cstdlib> // For random numbers
#include <algorithm>
#include <ctime>
#include <random>
#include <string>

#include <cmath>
#include <iostream>
#include <map>
#include <iomanip>

using std::vector;

void TestRunner::SetNumSamples(int n) 
{
	numSamples = std::min(INT_MAX, std::max(0, n));
}


vector<int> TestRunner::RunUniformTests()
{
	std::vector<int> randomNums;

	// Generate numbers based on the time
	std::srand(time(NULL));

	for (int i = 0; i < numSamples; i++) {
		int rNum = std::rand() % (RANDOM_MAX - RANDOM_MIN + 1) + RANDOM_MIN;
		randomNums.push_back(rNum);
	}

	return randomNums;
}

vector<int> TestRunner::RunNormalTests()
{
	std::vector<int> randomNums;

	std::random_device rd{};
	std::mt19937 gen{ rd() };

	// values near the mean are the most likely
	// standard deviation affects the dispersion of generated values from the mean
	std::normal_distribution d{ mean, stdDev };

	// draw a sample from the normal distribution and round it to an integer
	auto random_int = [&d, &gen] { return std::round(d(gen)); };

	for (int i = 0; i < numSamples; i++)
		randomNums.push_back(random_int());

	return randomNums;
}