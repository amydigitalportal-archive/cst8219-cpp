#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <vector>

using std::vector;

class TestRunner {
public:
	void SetNumSamples(int n);

	vector<int> RunUniformTests();
	vector<int> RunNormalTests();

private:
	int numSamples = 0;
	double mean = 0;
	double stdDev = 10;

	static const int RANDOM_MIN = -100;
	static const int RANDOM_MAX = 100;
};

#endif // TEST_RUNNER_H