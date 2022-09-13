// https://www.nowcoder.com/practice/15e41630514445719a942e004edc0a5b
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> a(20, vector<int>(2));
string s;

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1];
        }
        cin >> s;
        stack<pair<int, int>> st;
        int len = s.length();
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == ')')
            {
                auto y = st.top();
                st.pop();
                auto x = st.top();
                st.pop();
                if (x.second == y.first)
                {
                    res += x.second * x.first * y.second;
                    st.push({x.first, y.second});
                }
                else if (x.first == y.second)
                {
                    res += x.first * x.second * y.first;
                    st.push({x.second, y.first});
                }
            }
            else if (s[i] != '(')
            {
                int t = s[i] - 'A';
                st.push({a[t][0], a[t][1]});
            }
        }
        cout << res << endl;
    }
    return 0;
}