// https://www.nowcoder.com/practice/bfd8234bb5e84be0b493656e390bdebf
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));
        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                if (i < j)
                {
                    dp[i][j] = dp[i][i];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j];
                }
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}