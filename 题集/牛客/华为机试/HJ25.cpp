// https://www.nowcoder.com/practice/9a763ed59c7243bd8ab706b2da52b7fd
#include <bits/stdc++.h>
using namespace std;

bool isContain(string str, string target)
{
    return str.find(target) != str.npos;
}

int main()
{
    int Icount;
    cin >> Icount;
    vector<string> I;
    string temp;
    for (int i = 0; i < Icount; i++)
    {
        cin >> temp;
        I.push_back(temp);
    }

    int Rcount;
    cin >> Rcount;
    set<int> R;
    int t;
    for (int i = 0; i < Rcount; i++)
    {
        cin >> t;
        R.insert(t);
    }

    vector<int> res;
    for (int k : R)
    {
        string it = to_string(k);
        int count = 0;
        bool find = false;
        for (int i = 0; i < I.size(); i++)
        {
            if (I[i].find(it) != string::npos)
            {
                count++;
                if (!find)
                {
                    res.push_back(stoi(it));
                    find = true;
                }
            }
        }

        if (count > 0)
        {
            res.push_back(count);
            for (int j = 0; j < I.size(); j++)
            {
                if (I[j].find(it) != string::npos)
                {
                    res.push_back(j);
                    res.push_back(stoi(I[j]));
                }
            }
        }
    }

    cout << res.size() << " ";
    for (int num : res)
    {
        cout << num << " ";
    }
    return 0;
}