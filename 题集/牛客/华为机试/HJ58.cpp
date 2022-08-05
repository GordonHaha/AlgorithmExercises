// https://www.nowcoder.com/practice/69ef2267aafd4d52b250a272fd27052c
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            cin >> res[i];
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < k; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}