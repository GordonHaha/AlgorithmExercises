// https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string temp;
    bool flag;
    int x = 0, y = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ';')
        {
            temp += str[i];
        }
        else
        {
            if (temp.size() < 2 || (temp[0] != 'A' && temp[0] != 'S' && temp[0] != 'D' && temp[0] != 'W'))
            {
                temp = "";
                continue;
            }

            string tempNum = temp.substr(1);
            int num = 0;
            int j = 0;
            while (j < tempNum.length())
            {
                char c = tempNum[j];
                if (!isdigit(c))
                {
                    temp.clear();
                    break;
                }
                num = num * 10 + (c - '0');
                j++;
            }
            if (j != tempNum.length())
            {
                temp.clear();
                continue;
            }

            if (temp[0] == 'A')
            {
                x -= num;
            }
            else if (temp[0] == 'S')
            {
                y -= num;
            }
            else if (temp[0] == 'D')
            {
                x += num;
            }
            else if (temp[0] == 'W')
            {
                y += num;
            }
            temp.clear();
        }
    }
    cout << x << "," << y << endl;
    return 0;
}