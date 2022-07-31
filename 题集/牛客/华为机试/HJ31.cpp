// https://www.nowcoder.com/practice/81544a4989df4109b33c2d65037c5836
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> res;
    string str;
    string temp;
    while (cin >> str)
    {
        temp = "";
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                temp += str[i];
            }
            else
            {
                if (!temp.empty())
                {
                    res.push_back(temp);
                    temp = "";
                }
            }
        }
        res.push_back(temp);
    }

    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    return 0;
}