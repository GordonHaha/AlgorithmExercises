// https://www.nowcoder.com/practice/48b3cb4e3c694d9da5526e6255bb73c3
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> res;
    string temp;
    while (cin >> temp)
    {
        res.push_back(temp);
    }
    string ans;
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    return 0;
}