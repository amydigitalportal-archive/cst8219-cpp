#ifndef TEST_H
#define TEST_H

#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <vector>

#define UNIFORM_MIN -100
#define UNIFORM_MAX 100
#define NUM_BUCKETS 20

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

	int GetNumSamples() { return numSamples; }

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

	//virtual std::vector<T> GetHistogram() = 0;
	virtual std::vector<T> GetHistogram()
	{
		std::vector<T> histogram;

		T min = GetMin(), max = GetMax();
		T range = max - min;
		T bucketSize = range / NUM_BUCKETS;
		std::map<T, int> indexedRows{};

		// Initialize bucket brackets
		for (int bucketIndex = 0; bucketIndex < NUM_BUCKETS; bucketIndex++)
		{
			T startingPoint = min + (bucketIndex * bucketSize);
			indexedRows.emplace(startingPoint, 0);
		}

		// For each generated number
		for (T i : numbers)
		{
			// How far is the current i-value from the lowest number?
			T relativeGain = i - min;
			// Normalize relative gain per one point of the range
			T gainPerRangeValue = relativeGain / range;

			for (int b = 0; b < NUM_BUCKETS; b++)
			{
				T bucketStart = min + (b * bucketSize);
				T nextBucketStart = min + ((b + 1) * bucketSize);
				if (bucketStart < i && nextBucketStart > i) {
					indexedRows[bucketStart]++;
					break;
				}
			}
		}

		// For each bracket in the map, in ascending order...
		for (auto& [k, v] : indexedRows)
		{
			// ... add a bucket to the Histogram.
			histogram.push_back(v);
		}

		return histogram;
	}

	virtual std::string GetName() = 0;
};

template <class T>
class UniformTest : public Test<T>
{
public:
	UniformTest(int numSamples) : Test<T>(numSamples)
	{
		// Generate numbers based on the time
		std::srand(static_cast<unsigned int>(time(NULL)));

		for (int i = 0; i < numSamples; i++) {
			T rNum = std::rand() % (UNIFORM_MAX - UNIFORM_MIN + 1) + UNIFORM_MIN;
			this->numbers.push_back(rNum);
		}
	}
	~UniformTest() {}

	std::string GetName() override
	{
		return "Uniform Distribution";
	}
};

template<class T>
class NormalTest : public Test<T>
{
public:
	// Ref: https://en.cppreference.com/w/cpp/numeric/random/normal_distribution
	NormalTest(int numSamples) : Test<T>(numSamples)
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
			this->numbers.push_back(num());
		}
	}

	std::string GetName() override
	{
		return "Normal Distribution";
	}
};



#endif // !TEST_H