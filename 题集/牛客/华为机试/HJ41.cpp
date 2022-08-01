// https://www.nowcoder.com/practice/f9a4c19050fc477e9e27eb75f3bfd49c
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> weight(n);
        vector<int> num(n);
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        unordered_set<int> s;
        s.insert(0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= num[i]; j++)
            {
                unordered_set<int> temp(s);
                for (auto &it : temp)
                {
                    s.insert(it + weight[i]);
                }
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}