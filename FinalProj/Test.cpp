#include "Test.h"

#include <map>

using std::vector;

template <class T> vector<T> Test::GetHistogram()
{
    std::map<int, int> hist{};
    for (int n = 0; n != ; ++n)
        ++hist[random_int()];
}