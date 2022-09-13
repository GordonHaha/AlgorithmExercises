// https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        vector<string> res;
        string temp;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '"')
            {
                i++;
                while (str[i] != '"')
                {
                    temp += str[i];
                    i++;
                }
                res.push_back(temp);
                temp = "";
            }
            else if (str[i] == ' ')
            {
                if (!temp.empty())
                {
                    res.push_back(temp);
                    temp = "";
                }
            }
            else
            {
                temp += str[i];
            }
        }
        if (!temp.empty())
        {
            res.push_back(temp);
        }

        cout << res.size() << endl;
        for (string s : res)
        {
            cout << s << endl;
        }
    }
    return 0;
}