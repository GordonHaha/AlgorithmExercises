// https://www.nowcoder.com/practice/5af18ba2eb45443aa91a11e848aa6723
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> res;
    string s;
    while (cin >> s)
    {
        res.push_back(s);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}