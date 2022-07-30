// https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        swap(s[left++], s[right--]);
    }
    cout << s << endl;
    return 0;
}