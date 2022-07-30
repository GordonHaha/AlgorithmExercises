// https://www.nowcoder.com/practice/28970c15befb4ff3a264189087b99ad4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        int n = str.length(), m = pattern.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true; // 都是空串时一定匹配
        // str为空串时的情况
        for(int i = 2;i <= m;i++) {
            if(pattern[i-1] == '*') {
                dp[0][i] = dp[0][i-2]; // 末尾星号时，因为可以匹配0次，只要前一位能匹配上就行
            }
        }
        
        for(int i = 1;i <= n; i++) {
            for(int j = 1;j <= m;j++) {
                // 末尾字符能匹配或者pattern末尾为.时，看上一位的匹配情况
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(pattern[j-1] == '*') {
                    // pattern末尾为*时
                    if(dp[i][j-1]) {
                        // *号前一位与str当前位匹配上时，*位匹配1次
                        dp[i][j] = dp[i][j-1];
                    } else if (j >= 2 && dp[i][j-2]) {
                        // *号前一位与str当前位置不匹配时，*位匹配0次
                        dp[i][j] = dp[i][j-2];
                    } else if(i >= 2 && j >= 2 && dp[i-1][j]) {
                        // *位匹配多次需要str末尾字符跟pattern*前一位匹配上 并且str末尾前一位字符也匹配上
                        dp[i][j] = str[i-1] == pattern[j-2] || pattern[j-2] == '.';
                    }
                }
            }
        }
        return dp[n][m];
    }
};