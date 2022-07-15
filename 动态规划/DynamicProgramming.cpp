#include <bits/stdc++.h>
using namespace std;

// // 斐波那契数列
// int Fibonacci(int n)
// {
//     int a = 1, b = 1, c = 1;
//     for (int i = 3; i <= n; i++)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//     }
//     return c;
// }

// /*
// 假设有排成一行的N个位置，记为1~N，N一定大于或等于2
// 开始时机器人在其中的M位置上（M一定是1~N中的一个）
// 如果机器人来到1位置，那么下一步只能往右来到2位置；
// 如果机器人来到N位置，那么下一步只能往左来到N-1位置；
// 如果机器人来到中间位置，那么下一步可以往左走或者往右走；
// 规定机器人必须走k步，最终能来到P位置（P也是1~N中的一个）的方法有多少种。
// 给定四个参数N、M、K、P，返回方法数。
// */

// // 方法一

// // 机器人当前来到的位置是cur
// // 机器人还有rest步需要去走
// // 最终的目标是P
// // 有哪些位置？1~N
// // 返回：机器人从cur出发， 走过rest步之后，最终停在P的方法数，是多少？
// int process1(int cur, int rest, int P, int N)
// {
//     if (rest == 0)
//     {
//         return cur == P ? 1 : 0;
//     }

//     // rest > 0,还有步数要走
//     if (cur == 1) // 1 -> 2 左边界 往右走
//     {
//         return process1(2, rest - 1, P, N);
//     }

//     if (cur == N) // N-1 <- N 右边界 往左走
//     {
//         return process1(N - 1, rest - 1, P, N);
//     }
//     // 中间位置
//     return process1(cur - 1, rest - 1, P, N) + process1(cur + 1, rest - 1, P, N);
// }

// int ways1(int N, int M, int P, int K)
// {
//     if (N < 2 || P < 1 || M < 1 || K < 1 || M > N || P > N)
//     {
//         return -1;
//     }
//     return process1(M, K, P, N);
// }

// // 方法二
// // cur范围：1~N
// // rest范围：0~K
// int process2(int cur, int rest, int P, int N, vector<vector<int>> &dp)
// {
//     if (dp[cur][rest] != -1)
//     {
//         return dp[cur][rest];
//     }

//     int ans = 0;
//     if (rest == 0)
//     {
//         ans = cur == P ? 1 : 0;
//     }
//     else if (cur == 1) // 1 -> 2 左边界 往右走
//     {
//         ans = process2(2, rest - 1, P, N, dp);
//     }
//     else if (cur == N) // N-1 <- N 右边界 往左走
//     {
//         ans = process2(N - 1, rest - 1, P, N, dp);
//     }
//     else
//     {
//         // 中间位置
//         ans = process2(cur - 1, rest - 1, P, N, dp) + process2(cur + 1, rest - 1, P, N, dp);
//     }
//     dp[cur][rest] = ans;
//     return ans;
// }

// int ways2(int N, int M, int P, int K)
// {
//     if (N < 2 || P < 1 || M < 1 || K < 1 || M > N || P > N)
//     {
//         return -1;
//     }
//     vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
//     return process2(M, K, P, N, dp);
// }

// // 方法三 动态规划版本

// int ways3(int N, int M, int P, int K)
// {
//     if (N < 2 || P < 1 || M < 1 || K < 1 || M > N || P > N)
//     {
//         return -1;
//     }

//     vector<vector<int>> dp(N + 1, vector<int>(K + 1));
//     dp[P][0] = 1; // dp[...][0] = 0;

//     for (int rest = 1; rest <= K; rest++)
//     {
//         dp[1][rest] = dp[2][rest - 1];
//         for (int cur = 2; cur < N; cur++)
//         {
//             dp[cur][rest] = dp[cur - 1][rest - 1] + dp[cur + 1][rest - 1];
//         }
//         dp[N][rest] = dp[N - 1][rest - 1];
//     }

//     return dp[M][K];
// }

// /*
// 给定一个整型数组arr，代表数值不同的纸牌排成一条线
// 玩家A和玩家B依次拿走每张纸牌
// 规定玩家A先拿，玩家B后拿
// 但是每个玩家每次只能拿走最左或最右的纸牌
// 玩家A和玩家B都绝顶聪明
// 请返回最后获胜者的分数。
// */

// // 方法一 暴力递归

// // arr[L...R],后手获得的最好分数返回去
// int f1(vector<int> &arr, int L, int R);

// int g1(vector<int> &arr, int L, int R)
// {
//     if (L == R)
//     {
//         return 0;
//     }
//     int p1 = f1(arr, L + 1, R); // 对手拿走了L位置的数
//     int p2 = f1(arr, L, R - 1); // 对手拿走了R位置的数
//     return min(p1, p2);
// }

// // arr[L...R],先手获得的最好分数返回去
// int f1(vector<int> &arr, int L, int R)
// {
//     if (L == R)
//     {
//         return arr[L];
//     }
//     int p1 = arr[L] + g1(arr, L + 1, R);
//     int p2 = arr[R] + g1(arr, L, R - 1);
//     return max(p1, p2);
// }

// // 根据规则，返回获胜者的分数
// int win1(vector<int> &arr)
// {
//     if (arr.empty())
//     {
//         return 0;
//     }

//     int first = f1(arr, 0, arr.size() - 1);
//     int second = g1(arr, 0, arr.size() - 1);
//     return max(first, second);
// }

// //方法二 动态规划
// // arr[L...R],后手获得的最好分数返回去
// int f2(vector<int> &arr, int L, int R, vector<vector<int>> &fmap, vector<vector<int>> &gmap);
// int g2(vector<int> &arr, int L, int R, vector<vector<int>> &fmap, vector<vector<int>> &gmap)
// {
//     if (gmap[L][R] != -1)
//     {
//         return gmap[L][R];
//     }
//     int ans = 0;
//     if (L != R)
//     {
//         int p1 = f2(arr, L + 1, R, fmap, gmap); // 对手拿走了L位置的数
//         int p2 = f2(arr, L, R - 1, fmap, gmap); // 对手拿走了R位置的数
//         ans = min(p1, p2);
//     }
//     gmap[L][R] = ans;
//     return ans;
// }

// // arr[L...R],先手获得的最好分数返回去
// int f2(vector<int> &arr, int L, int R, vector<vector<int>> &fmap, vector<vector<int>> &gmap)
// {
//     if (fmap[L][R] != -1)
//     {
//         return fmap[L][R];
//     }
//     int ans = 0;
//     if (L == R)
//     {
//         ans = arr[L];
//     }
//     else
//     {
//         int p1 = arr[L] + g2(arr, L + 1, R, fmap, gmap);
//         int p2 = arr[R] + g2(arr, L, R - 1, fmap, gmap);
//         ans = max(p1, p2);
//     }
//     fmap[L][R] = ans;
//     return ans;
// }

// // 根据规则，返回获胜者的分数
// int win2(vector<int> &arr)
// {
//     if (arr.empty())
//     {
//         return 0;
//     }
//     int N = arr.size();
//     vector<vector<int>> fmap(N, vector<int>(N, -1));
//     vector<vector<int>> gmap(N, vector<int>(N, -1));

//     int first = f2(arr, 0, N - 1, fmap, gmap);
//     int second = g2(arr, 0, N - 1, fmap, gmap);
//     return max(first, second);
// }

// // 方法三 动态规划-严格表依赖

// // 根据规则，返回获胜者的分数
// int win3(vector<int> &arr)
// {
//     if (arr.empty())
//     {
//         return 0;
//     }
//     int N = arr.size();
//     vector<vector<int>> fmap(N, vector<int>(N));
//     vector<vector<int>> gmap(N, vector<int>(N));

//     for (int i = 0; i < N; i++)
//     {
//         fmap[i][i] = arr[i];
//     }

//     for (int startCol = 1; startCol < N; startCol++)
//     {
//         int L = 0;
//         int R = startCol;
//         while (R < N)
//         {
//             fmap[L][R] = max(arr[L] + gmap[L + 1][R], arr[R] + gmap[L][R - 1]);
//             gmap[L][R] = min(fmap[L + 1][R], fmap[L][R - 1]);
//             L++;
//             R++;
//         }
//     }

//     return max(fmap[0][N - 1], gmap[0][N - 1]);
// }

// /*
// 背包问题
// 一共有N件物品，第i（i从1开始）件物品的重量为w[i]，价值为v[i]。在总重量不超过背包承载上限bag的情况下，能够装入背包的最大价值是多少？
// */

// // 方法一 暴力递归
// // 当前考虑到了index号货物，index...所有的货物可以自由选择
// // 做的选择不能超过背包容量
// // 返回最大价值
// int process(vector<int> &w, vector<int> &v, int index, int rest)
// {
//     if (rest < 0)
//     {
//         return -1;
//     }
//     if (index == w.size())
//     {
//         return 0;
//     }

//     // 有货，index位置的货
//     // bag有空间，0
//     // 不要当前的货
//     int p1 = process(w, v, index + 1, rest);

//     // 要当前的货
//     int p2 = 0;
//     int next = process(w, v, index + 1, rest - w[index]);
//     if (next != -1)
//     {
//         p2 = v[index] + next;
//     }
//     return max(p1, p2);
// }

// // 所有的货，重量和价值，都在w和v数组里
// // 为了方便，其中没有负数
// // bag背包容量，不能超过这个载重
// // 返回：不超重的情况下，能够得到的最大价值

// int maxValue(vector<int> &w, vector<int> &v, int bag)
// {
//     if (w.empty() || v.empty() || w.size() != v.size())
//     {
//         return 0;
//     }

//     return process(w, v, 0, bag);
// }

// // 方法二 动态规划

// int dp(vector<int> &w, vector<int> &v, int bag)
// {
//     if (w.empty() || v.empty() || w.size() != v.size())
//     {
//         return 0;
//     }
//     // index 0~N
//     // rest 负~bag
//     int N = w.size();
//     vector<vector<int>> dp(N + 1, vector<int>(bag + 1));
//     for (int index = N - 1; index >= 0; index--)
//     {
//         for (int rest = 0; rest <= bag; rest++)
//         {
//             int p1 = dp[index + 1][rest];
//             int p2 = 0;
//             int next = rest - w[index] < 0 ? -1 : dp[index + 1][rest - w[index]];
//             if (next != -1)
//             {
//                 p2 = v[index] + next;
//             }
//             dp[index][rest] = max(p1, p2);
//         }
//     }

//     return dp[0][bag];
// }

// /*
// 规定1和A对应、2和B对应、3和C对应...
// 那么一个数字字符串比如“111”就可以转化为；
// “AAA”、“KA”、“AK”
// 给定一个只有数字字符串组成的字符串str，返回有多少种转化结果
// */

// // 方法一 暴力递归
// // str[0...i-1]转化无需过问
// // str[i......]去转化，返回有多少种转化方法
// int processNum(string &str, int i)
// {
//     if (i == str.length())
//     {
//         return 1;
//     }
//     // i没到最后，说明有字符
//     // 可能性一，单字符转
//     if (str[i] == '0') // 之前的决定有问题
//     {
//         return 0;
//     }

//     // str[i] != '0'

//     int ways = processNum(str, i + 1);

//     // 可能性二，双字符转
//     if (i + 1 < str.length() && (str[i] - '0') * 10 + str[i + 1] - '0' < 27)
//     {
//         ways += processNum(str, i + 2);
//     }
//     return ways;
// }

// // str只含有数字字符0~9
// // 返回多少种转化方案
// int number(string &str)
// {
//     if (str.empty())
//     {
//         return 0;
//     }
//     return processNum(str, 0);
// }

// // 方法二 动态规划

// int dp(string &s)
// {
//     if (s.empty())
//     {
//         return 0;
//     }

//     int N = s.length();
//     vector<int> dp(N + 1);
//     dp[N] = 1;
//     for (int i = N - 1; i >= 0; i--)
//     {
//         if (s[i] != '0')
//         {
//             int ways = dp[i + 1];
//             if (i + 1 < s.length() && (s[i] - '0') * 10 + s[i + 1] - '0' < 27)
//             {
//                 ways += dp[i + 2];
//             }
//             dp[i] = ways;
//         }
//     }

//     return dp[0];
// }

/*
给定一个字符串str，给定一个字符串类型的数组arr，出现的字符都是小写英文。
arr每一个字符串，代表一张贴纸，你可以把单个字符剪开使用，目的是拼出str来
返回需要至少多少张贴纸可以完成这个任务。
例子：str = "babac", arr = {"ba","c","abcd"}
ba+ba+c 3 abcd + abcd 2
所以返回2
*/

// 方法一 暴力递归
string minusStr(string s1, string s2)
{
    vector<int> count(26);
    for (char cha : s1)
    {
        count[cha - 'a']++;
    }
    for (char cha : s2)
    {
        count[cha - 'a']--;
    }

    string builder = "";
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                builder += (char)(i + 'a');
            }
        }
    }
    return builder;
}

// 所有贴纸stickers，每一种贴纸都有无穷张
// target
// 最少张数
int processStr1(vector<string> &stickers, string target)
{
    if (target.length() == 0)
    {
        return 0;
    }

    int minVal = INT_MAX;
    for (string first : stickers)
    {
        string rest = minusStr(target, first);
        if (rest.length() != target.length())
        {
            minVal = min(minVal, processStr1(stickers, rest));
        }
    }
    return minVal + (minVal == INT_MAX ? 0 : 1);
}

int minStickers1(vector<string> &stickers, string target)
{
    int ans = processStr1(stickers, target);
    return ans == INT_MAX ? -1 : ans;
}

// 方法二

// stickers[i] 数组，当初i号贴纸的字符统计
int processStr2(vector<vector<int> > &stickers, string t)
{
    if (t.length() == 0)
    {
        return 0;
    }

    // target做出词频统计
    // target aabbc 2 2 1...
    //              0 1 2..
    vector<int> tcounts(26);
    for (char cha : t)
    {
        tcounts[cha - 'a']++;
    }
    int N = stickers.size();
    int minVal = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        // 尝试第一张贴纸是谁
        vector<int> sticker = stickers[i];
        // 最关键的优化（重要的剪枝！这一步也是贪心~）
        if (sticker[t[0] - 'a'] > 0)
        {
            string builder = "";
            for (int j = 0; j < 26; j++)
            {
                if (tcounts[j] > 0)
                {
                    int nums = tcounts[j] - sticker[j];
                    for (int k = 0; k < nums; k++)
                    {
                        builder += (char)(j + 'a');
                    }
                }
            }
            minVal = min(minVal, processStr2(stickers, builder));
        }
    }
    return minVal + (minVal == INT_MAX ? 0 : 1);
}

int minStickers2(vector<string> &stickers, string &target)
{
    int N = stickers.size();
    // 关键优化（用词频表替代贴纸数组）
    vector<vector<int> > counts(N, vector<int>(26));
    for (int i = 0; i < N; i++)
    {
        string str = stickers[i];
        for (char cha : str)
        {
            counts[i][cha - 'a']++;
        }
    }
    int ans = processStr2(counts, target);
    return ans == INT_MAX ? -1 : ans;
}

// // 方法三 动态规划

int processStr3(vector<vector<int>> &stickers, string t, unordered_map<string, int> &dp)
{
    if (dp.find(t) != dp.end())
    {
        return dp[t];
    }

    vector<int> tcounts(26);
    for (char cha : t)
    {
        tcounts[cha - 'a']++;
    }
    int N = stickers.size();
    int minVal = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        // 尝试第一张贴纸是谁
        vector<int> sticker = stickers[i];
        // 最关键的优化（重要的剪枝！这一步也是贪心~）
        if (sticker[t[0] - 'a'] > 0)
        {
            string builder = "";
            for (int j = 0; j < 26; j++)
            {
                if (tcounts[j] > 0)
                {
                    int nums = tcounts[j] - sticker[j];
                    for (int k = 0; k < nums; k++)
                    {
                        builder += (char)(j + 'a');
                    }
                }
            }
            minVal = min(minVal, processStr3(stickers, builder, dp));
        }
    }
    int ans = minVal + (minVal == INT_MAX ? 0 : 1);
    dp.emplace(t, ans);
    return ans;
}

int minStickers3(vector<string> &stickers, string target)
{
    int N = stickers.size();
    vector<vector<int>> counts(N, vector<int>(26));
    for (int i = 0; i < N; i++)
    {
        string str = stickers[i];
        for (char cha : str)
        {
            counts[i][cha - 'a']++;
        }
    }

    unordered_map<string, int> dp;
    dp.emplace("", 0);
    int ans = processStr3(counts, target, dp);
    return ans == INT_MAX ? -1 : ans;
}

/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。如果不存在公共子序列，返回 0 。
一个字符串的子序列是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的公共子序列是这两个字符串所共同拥有的子序列。

示例 1：
输入：text1 = "abcde", text2 = "ace"
输出：3
解释：最长公共子序列是 "ace" ，它的长度为 3 。

示例 2：
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。

示例 3：
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
 
提示：
1 <= text1.length, text2.length <= 1000
text1 和 text2 仅由小写英文字符组成。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-common-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 方法一 暴力递归
// str1[0...i]与str2[0...j]最长公共子序列多长
int processLCS1(string str1, string str2, int i, int j) {
    if (i == 0 && j == 0)
    {
        return str1[0] == str2[0] ? 1 : 0;
    }
    if (i == 0)
    {
        return str1[0] == str2[j] ? 1 : processLCS1(str1, str2, 0, j - 1);
    }
    if (j==0)
    {
        return str1[i] == str2[0] ? 1 : processLCS1(str1, str2, i - 1, 0);
    }

    int p1 = processLCS1(str1, str2, i - 1, j);
    int p2 = processLCS1(str1, str2, i, j - 1);
    int p3 = str1[i] == str2[j] ? (1 + processLCS1(str1, str2, i - 1, j - 1)) : INT_MIN;

    return max(p1, max(p2, p3));
}

int longestCommonSubsequence1(string text1, string text2)
{
    if (text1.empty() || text2.empty())
    {
        return 0;
    }
    return processLCS1(text1, text2, text1.length() - 1, text2.length() - 1);
}

// 方法二 动态规划

int longestCommonSubsequence2(string text1, string text2)
{
    if (text1.empty() || text2.empty())
    {
        return 0;
    }

    int N = text1.length();
    int M = text2.length();
    vector<vector<int>> dp(N, vector<int>(M));
    dp[0][0] = text1[0] == text2[0] ? 1 : 0;
    for (int j = 1; j < M; j++)
    {
        dp[0][j] = text1[0] == text2[j] ? 1 : dp[0][j - 1];
    }
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = text1[i] == text2[0] ? 1 : dp[i - 1][0];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            int p1 = dp[i - 1][j];
            int p2 = dp[i][j - 1];
            int p3 = text1[i] == text2[j] ? (1 + dp[i - 1][j - 1]) : 0;
            dp[i][j] = max(p1, max(p2, p3));
        }
    }

    return dp[N - 1][M - 1];
}

/*
给定一个字符串str，返回这个字符串的最长回文子序列长度
比如：str = "a12b3c43def2ghi1kpm"
最长回文子序列是"1234321"或者"123c321"，返回长度7
*/



int main()
{
    // vector<int> arr{5, 7, 4, 5, 8, 1, 6, 0, 3, 4, 6, 1, 7};
    // cout << win1(arr) << endl;
    // cout << win2(arr) << endl;
    // cout << win3(arr) << endl;

    // string str = "11111";
    // cout << number(str) << endl;
    // cout << dp(str) << endl;

    // vector<string> stickers{"bbc", "cck", "kkb", "bab"};
    // string target = "aaabbbck";
    // cout << minStickers1(stickers, target) << endl;
    // cout << minStickers2(stickers, target) << endl;
    // cout << minStickers3(stickers, target) << endl;
    return 0;
}
