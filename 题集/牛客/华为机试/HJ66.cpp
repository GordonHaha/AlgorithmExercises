// https://www.nowcoder.com/practice/ca6ac6ef9538419abf6f883f7d6f6ee5
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<pair<string, string>> input = {{"reset", ""}, {"reset", "board"}, {"board", "add"}, {"board", "delete"}, {"reboot", "backplane"}, {"backplane", "abort"}};
    vector<string> output = {"reset what", "board fault", "where to add", "no board at all", "impossible", "install first"};

    string str;
    while (getline(cin, str))
    {
        stringstream ss(str);
        string key1, key2;
        getline(ss, key1, ' ');
        getline(ss, key2, ' ');
        int count = 0;
        string res;
        for (auto it = input.begin(); it != input.end(); it++)
        {
            int i1 = it->first.find(key1);
            int i2;
            if (!key2.empty())
            {
                i2 = it->second.find(key2);
            }
            else if (key2.empty() && it->second.empty())
            {
                i2 = 0;
            }
            else
            {
                i2 = -1;
            }
            if (i1 == 0 && i2 == 0)
            {
                count++;
                res = output[it - input.begin()];
            }
        }
        if (count == 1)
        {
            cout << res << endl;
        }
        else
        {
            cout << "unknown command" << endl;
        }
    }
    return 0;
}