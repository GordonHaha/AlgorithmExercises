// https://www.nowcoder.com/practice/2de4127fda5e46858aa85d254af43941
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << endl;
    return 0;
}