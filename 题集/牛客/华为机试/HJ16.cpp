// https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    int N, m;
    cin >> N >> m;
    N /= 10;
    vector<vector<int>> v(m + 1, vector<int>(3, 0));
    vector<vector<int>> w(m + 1, vector<int>(3, 0));

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a /= 10, b *= a;
        if (c == 0)
        {
            v[i][0] = a;
            w[i][0] = b;
        }
        else
        {
            if (v[c][1] == 0)
            {
                v[c][1] = a;
                w[c][1] = b;
            }
            else
            {
                v[c][2] = a;
                w[c][2] = b;
            }
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(N + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int a = v[i][0], b = w[i][0];
            if (a == 0)
            {
                // 没有对应编号的商品，直接跳过
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            int c = v[i][1], d = w[i][1];
            int e = v[i][2], f = w[i][2];
            dp[i][j] = j >= a ? max(dp[i - 1][j - a] + b, dp[i - 1][j]) : dp[i - 1][j];
            dp[i][j] = j >= (a + c) ? max(dp[i - 1][j - a - c] + b + d, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (a + e) ? max(dp[i - 1][j - a - e] + b + f, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= (a + c + e) ? max(dp[i - 1][j - a - c - e] + b + d + f, dp[i][j]) : dp[i][j];
        }
    }
    cout << dp[m][N] * 10 << endl;
    return 0;
}