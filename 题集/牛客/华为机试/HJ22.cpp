// https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> temp;
    int num;
    while (cin >> num)
    {
        if (num == 0)
            break;
        temp.push_back(num);
    }

    for (int n : temp)
    {
        int count = 0;
        int tcount = 0;
        while (n >= 3)
        {
            tcount = n / 3;
            n = n % 3 + tcount;
            count += tcount;
        }

        if (n == 2)
        {
            // 剩两个空瓶时，可以借一瓶凑数
            count++;
        }
        cout << count << endl;
    }
    return 0;
}