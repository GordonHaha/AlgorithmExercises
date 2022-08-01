// https://www.nowcoder.com/practice/a30bbc1a0aca4c27b86dd88868de4a4a
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int n;
    cin >> str >> n;
    cout << str.substr(0, n);
    return 0;
}