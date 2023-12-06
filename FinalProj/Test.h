#ifndef TEST_H
#define TEST_H

#include <ctime>
#include <iostream>
#include <random>
#include <vector>

#define RANDOM_MIN -100
#define RANDOM_MAX 100

template <class T>
class Test {
private:
	int numSamples;

protected:
	std::vector<T> numbers;

public:
	Test(int numSamples) {
		this->numSamples = numSamples;
	}
	//virtual ~Test() = 0;

	virtual T GetMin()
	{
		int smallest = 0;
		for (int i : numbers)
			if (i < smallest) smallest = i;
		return smallest;
	}

	virtual T GetMax()
	{
		int largest = 0;
		for (int i : numbers)
			if (i > largest) largest = i;
		return largest;
	}

	virtual T GetMean()
	{
		int sum = 0;
		for (int i : numbers)
			sum += i;
		return static_cast<T>(sum / numbers.size());
	}

	virtual T GetMedian()
	{
		sort(numbers.begin(), numbers.end());

		size_t n = numbers.size();
		if (n % 2 == 0) // for even sample sizes...
		{
			T lowerMed = numbers[n / 2];
			T upperMed = numbers[n / 2 + 1];
			return (lowerMed + upperMed) / 2;
		}
		else // for odd sample sizes...
		{
			return numbers[n / 2];
		}
	}

	virtual std::vector<T> GetHistogram()
	{
		std::vector<T> buckets;
		const int numBuckets = 20;

		T min = GetMin();
		T max = GetMax();

		return buckets;
	}

	static const int SAMPLE_MIN = 20;
	static const int SAMPLE_MAX = 1000;
};

class UniformTest : public Test<int>
{
public:
	UniformTest(int numSamples) : Test<int>(numSamples)
	{
		// Generate numbers based on the time
		std::srand(static_cast<unsigned int>(time(NULL)));

		for (int i = 0; i < numSamples; i++) {
			int rNum = std::rand() % (RANDOM_MAX - RANDOM_MIN + 1) + RANDOM_MIN;
			numbers.push_back(rNum);

			std::cout << numbers[i] << std::endl;
		}
	}
	~UniformTest() {}
};



#endif // !TEST_H