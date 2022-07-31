// https://www.nowcoder.com/practice/5190a1db6f4f4ddb92fd9c365c944584
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<vector<char>> temp(26);
    for (char c : str)
    {
        if (c >= 'a' && c <= 'z')
        {
            temp[c - 'a'].push_back(c);
        }
        else if (c >= 'A' && c <= 'Z')
        {
            temp[c - 'A'].push_back(c);
        }
    }

    string res;
    int i = 0, j = 0;
    for (char c : str)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (i >= temp.size())
            {
                break;
            }
            while (temp[i].empty())
            {
                i++;
            }
            res += temp[i][j];
            j++;
            if (j == temp[i].size())
            {
                i++;
                j = 0;
            }
        }
        else
        {
            res += c;
        }
    }
    cout << res << endl;
    return 0;
}