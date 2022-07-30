
// https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    vector<string> arr;
    while (cin >> str)
    {
        arr.push_back(str);
    }
    cout << arr[arr.size() - 1].size() << endl;
    return 0;
}