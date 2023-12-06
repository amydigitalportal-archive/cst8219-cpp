#ifndef TEST_H
#define TEST_H

#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <vector>

#define UNIFORM_MIN -100
#define UNIFORM_MAX 100

using namespace std;


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
		T smallest = 0;
		for (T i : numbers)
			if (i < smallest) smallest = i;
		return smallest;
	}

	virtual T GetMax()
	{
		T largest = 0;
		for (T i : numbers)
			if (i > largest) largest = i;
		return largest;
	}

	virtual T GetMean()
	{
		T sum = 0;
		for (T i : numbers)
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
			int rNum = std::rand() % (UNIFORM_MAX - UNIFORM_MIN + 1) + UNIFORM_MIN;
			numbers.push_back(rNum);

			std::cout << numbers[i] << std::endl;
		}
	}
	~UniformTest() {}

	std::vector<int> GetHistogram() override
	{


		return Test::GetHistogram();
	}

};

class NormalTest : public Test<double>
{
public:
	// Ref: https://en.cppreference.com/w/cpp/numeric/random/normal_distribution
	NormalTest(int numSamples) : Test<double>(numSamples)
	{
		std::random_device rd{};
		std::mt19937 gen{ rd() };

		double mean = 0.0, sd = 10.0;

		// values near the mean are the most likely
		// standard deviation affects the dispersion of generated values from the mean
		std::normal_distribution normal_dist{ mean, sd };

		// draw a sample from the normal distribution and round it to an integer
		auto num = [&normal_dist, &gen] {
			return static_cast<double>(normal_dist(gen));
		};

		for (int i = 0; i < numSamples; i++)
		{
			numbers.push_back(num());
			//std::cout << numbers[i] << std::endl;
		}
	}

	std::vector<double> GetHistogram() override
	{
		double min = GetMin();
		cout << "Min: " << min << endl;
		double max = GetMax();
		cout << "Max: " << max << endl;

		// TODO
		return Test::GetHistogram();
	}
};



#endif // !TEST_H