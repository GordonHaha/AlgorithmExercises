// https://www.nowcoder.com/practice/eb94f6a5b2ba49c6ac72d40b5ce95f50
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> set;
    for (char c : s)
    {
        set.insert(c);
    }
    cout << set.size() << endl;
    return 0;
}