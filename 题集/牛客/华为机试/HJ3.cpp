// https://www.nowcoder.com/practice/3245215fffb84b7b81285493eae92ff0
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int i = 0;
    set<int> s;
    while (cin >> i)
    {
        s.insert(i);
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}