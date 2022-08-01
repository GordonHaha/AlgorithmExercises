// https://www.nowcoder.com/practice/1364723563ab43c99f3d38b5abef83bc
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> to19 = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector<string> hund = {"hundred", "thousand", "million", "billion"};
vector<int> ihund = {(int)1e2, (int)1e3, (int)1e6, (int)1e9, (int)1e12};

string intToE(long long n)
{
    if (n < 20)
    {
        return to19[n - 1];
    }
    else if (n < 1e2)
    {
        return tens[n / 10 - 2] + (n % 10 ? " " + to19[n % 10 - 1] : "");
    }
    else
    {
        for (int i = 0; i < ihund.size(); i++)
        {
            if (n < ihund[i + 1])
            {
                return intToE(n / ihund[i]) + " " + hund[i] + (n % ihund[i] ? (i ? " " : " and ") + intToE(n % ihund[i]) : "");
            }
        }
    }
    return "";
}

int main()
{
    long long n;
    cin >> n;
    cout << intToE(n) << endl;
    return 0;
}