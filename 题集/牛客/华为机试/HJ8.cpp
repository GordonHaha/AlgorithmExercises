// https://www.nowcoder.com/practice/de044e89123f4a7482bd2b214a685201
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int k, v;
    while (cin >> k)
    {
        cin >> v;
        mp[k] += v;
    }
    for (pair<int, int> pair : mp)
    {
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}