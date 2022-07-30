// https://www.nowcoder.com/practice/89865d4375634fc484f3a24b7fe65665
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int len = m + n;
        int lenA = m - 1, lenB = n - 1;
        for (int i = len - 1; i >= 0; i--)
        {
            if (lenA >= 0 && lenB >= 0)
            {
                if (A[lenA] > B[lenB])
                {
                    A[i] = A[lenA];
                    lenA--;
                }
                else
                {
                    A[i] = B[lenB];
                    lenB--;
                }
            }
            else if (lenB >= 0)
            {
                A[i] = B[lenB];
                lenB--;
            }
        }
    }
};