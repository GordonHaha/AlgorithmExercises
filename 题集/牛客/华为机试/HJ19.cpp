// https://www.nowcoder.com/practice/2baa6aba39214d6ea91a2e03dff3fbeb
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    map<string, int> map;
    deque<string> dq;
    while (getline(cin, str))
    {
        str = str.substr(str.find_last_of('\\') + 1);
        int pos = str.find_last_of(' ');
        if (pos > 16)
        {
            str = str.substr(pos - 16);
        }

        if (map.count(str) == 0)
        {
            dq.push_back(str);
        }
        map[str]++;
        if (dq.size() > 8)
            dq.pop_front();
    }

    for (auto s : dq)
    {
        cout << s << " " << map[s] << endl;
    }
    return 0;
}