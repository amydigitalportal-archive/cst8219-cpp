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

	virtual std::vector<T> GetHistogram() = 0;

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

			//std::cout << numbers[i] << std::endl;
		}
	}
	~UniformTest() {}

	std::vector<int> GetHistogram() override
	{
		std::vector<int> histogram;
	
		int min = GetMin(), max = GetMax();
		int range = max - min;
		double bucketSize = range / NUM_BUCKETS;
		std::map<int, int> indexedRows{};

		// Initialize bucket brackets
		for (int bucketIndex = 0; bucketIndex < NUM_BUCKETS; bucketIndex++)
		{
			int startingPoint = min + (int)(bucketIndex * bucketSize);
			indexedRows.emplace(std::make_pair(startingPoint, 0));
		}

		// For each generated number
		for (int i : numbers)
		{
			// How far is the current i-value from the lowest number?
			int relativeGain = i - min;
			// Normalize relative gain per one point of the range
			double gainPerRangeValue = (double)relativeGain / range;

			for (int b = 0; b < NUM_BUCKETS; b++)
			{
				int bucketStart = min + (int)(b * bucketSize);
				int nextBucketStart = min + (int)((b + 1) * bucketSize);
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
		}
	}

	std::vector<double> GetHistogram() override
	{
		std::vector<double> histogram;

		double min = GetMin(), max = GetMax();
		double range = max - min;
		double bucketSize = range / NUM_BUCKETS;
		std::map<double, int> indexedRows{};

		// Initialize bucket brackets
		for (int bucketIndex = 0; bucketIndex < NUM_BUCKETS; bucketIndex++)
		{
			double startingPoint = min + (bucketIndex * bucketSize);
			indexedRows.emplace(std::make_pair(startingPoint, 0));
		}

		// For each generated number
		for (double genNum : numbers)
		{
			// How far is the current i-value from the lowest number?
			double relativeGain = genNum - min;
			// Normalize relative gain per one point of the range
			double gainPerRangeValue = relativeGain / range;
			
			for (int b = 0; b < NUM_BUCKETS; b++)
			{
				double bucketStart = min + (b * bucketSize);
				double nextBucketStart = min + ((b + 1) * bucketSize);
				if (bucketStart < genNum && nextBucketStart > genNum) {
					int currentCount = indexedRows[bucketStart];
					indexedRows.insert_or_assign(bucketStart, currentCount + 1);
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
};



#endif // !TEST_H