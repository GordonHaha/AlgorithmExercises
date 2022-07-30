// https://www.nowcoder.com/practice/3ab09737afb645cc82c35d56a5ce802a
#include <iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;
    if (n + 0.5 >= int(n) + 1)
    {
        cout << int(n) + 1 << endl;
    }
    else
    {
        cout << int(n) << endl;
    }
    return 0;
}