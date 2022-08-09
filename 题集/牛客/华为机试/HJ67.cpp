// https://www.nowcoder.com/practice/fbc417f314f745b1978fc751a54ac8cb
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(vector<double> v, double result)
{
    if (v.empty())
    {
        return result == 24;
    }

    for (int i = 0; i < v.size(); i++)
    {
        vector<double> temp(v);
        temp.erase(temp.begin() + i);
        if (check(temp, result + v[i]) || check(temp, result - v[i]) || check(temp, result * v[i]) || check(temp, result / v[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<double> v(4);
    while (cin >> v[0] >> v[1] >> v[2] >> v[3])
    {
        if (check(v, 0))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}