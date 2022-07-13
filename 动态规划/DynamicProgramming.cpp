#include <bits/stdc++.h>
using namespace std;

// 斐波那契数列
int Fibonacci(int n)
{
    int a = 1, b = 1, c = 1;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

/*
假设有排成一行的N个位置，记为1~N，N一定大于或等于2
开始时机器人在其中的M位置上（M一定是1~N中的一个）
如果机器人来到1位置，那么下一步只能往右来到2位置；
如果机器人来到N位置，那么下一步只能往左来到N-1位置；
如果机器人来到中间位置，那么下一步可以往左走或者往右走；
规定机器人必须走k步，最终能来到P位置（P也是1~N中的一个）的方法有多少种。
给定四个参数N、M、K、P，返回方法数。
*/

// 方法一

// 机器人当前来到的位置是cur
// 机器人还有rest步需要去走
// 最终的目标是P
// 有哪些位置？1~N
// 返回：机器人从cur出发， 走过rest步之后，最终停在P的方法数，是多少？
int process1(int cur, int rest, int P, int N)
{
    if (rest == 0)
    {
        return cur == P ? 1 : 0;
    }

    // rest > 0,还有步数要走
    if (cur == 1) // 1 -> 2 左边界 往右走
    {
        return process1(2, rest - 1, P, N);
    }

    if (cur == N) // N-1 <- N 右边界 往左走
    {
        return process1(N - 1, rest - 1, P, N);
    }
    // 中间位置
    return process1(cur - 1, rest - 1, P, N) + process1(cur + 1, rest - 1, P, N);
}

int ways1(int N, int M, int P, int K)
{
    if (N < 2 || P < 1 || M < 1 || K < 1 || M > N || P > N)
    {
        return -1;
    }
    return process1(M, K, P, N);
}

// 方法二
// cur范围：1~N
// rest范围：0~K
int process2(int cur, int rest, int P, int N, vector<vector<int>> &dp)
{
    if (dp[cur][rest] != -1)
    {
        return dp[cur][rest];
    }

    int ans = 0;
    if (rest == 0)
    {
        ans = cur == P ? 1 : 0;
    }
    else if (cur == 1) // 1 -> 2 左边界 往右走
    {
        ans = process2(2, rest - 1, P, N, dp);
    }
    else if (cur == N) // N-1 <- N 右边界 往左走
    {
        ans = process2(N - 1, rest - 1, P, N, dp);
    }
    else
    {
        // 中间位置
        ans = process2(cur - 1, rest - 1, P, N, dp) + process2(cur + 1, rest - 1, P, N, dp);
    }
    dp[cur][rest] = ans;
    return ans;
}

int ways2(int N, int M, int P, int K)
{
    if (N < 2 || P < 1 || M < 1 || K < 1 || M > N || P > N)
    {
        return -1;
    }
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
    return process2(M, K, P, N, dp);
}

// 方法三 动态规划版本

int ways3(int N, int M, int P, int K)
{
    if (N < 2 || P < 1 || M < 1 || K < 1 || M > N || P > N)
    {
        return -1;
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1));
    dp[P][0] = 1; // dp[...][0] = 0;

    for (int rest = 1; rest <= K; rest++)
    {
        dp[1][rest] = dp[2][rest - 1];
        for (int cur = 2; cur < N; cur++)
        {
            dp[cur][rest] = dp[cur - 1][rest - 1] + dp[cur + 1][rest - 1];
        }
        dp[N][rest] = dp[N - 1][rest - 1];
    }

    return dp[M][K];
}




int main()
{
    cout << ways1(10, 1, 6, 9) << endl;
    cout << ways2(10, 1, 6, 9) << endl;
    cout << ways3(10, 1, 6, 9) << endl;
    return 0;
}