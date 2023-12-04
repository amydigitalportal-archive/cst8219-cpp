#ifndef TEST_H
#define TEST_H


#include <vector>

template <class T>
class Test {
protected:
	std::vector<T> numbers;

public:
	Test(int numSamples);
	T GetMin();
	T GetMax();
	T GetMean();
	T GetMedian();

	std::vector<T> GetHistogram();
};

#endif // !TEST_H