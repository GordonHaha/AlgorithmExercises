#include <iostream>
#include <vector>
using namespace std;

// 64位位图
class bitmap
{
private:
    vector<long> bits;

public:
    bitmap(size_t range) : bits((range + 64) >> 6) {}

    void addNum(const size_t num)
    {
        bits[num >> 6] |= (1L << (num & 63));
    }

    void deleteNum(const size_t num)
    {
        bits[num >> 6] &= ~(1L << (num & 63));
    }

    bool containsNum(const size_t num)
    {
        return (bits[num >> 6] & (1L << (num & 63))) != 0;
    }
};
