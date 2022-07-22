// https://www.nowcoder.com/practice/31c1aed01b394f0b8b7734de0324e00f
#include<bits/stdc++.h>
using namespace std;

long long maxWater(vector<int> &arr)
{
  if(arr.empty())
      return 0;
  int left = 0, right = arr.size() - 1;
  int maxL = 0, maxR = 0;
  long long area = 0;
  while (left < right)
  {
    // 维护左右最高边界
      maxL = max(maxL, arr[left]);
      maxR = max(maxR, arr[right]);

    if(maxL < maxR) {
        area += maxL - arr[left++];
    } else {
        area += maxR - arr[right--];
    }
  }
  return area;
}