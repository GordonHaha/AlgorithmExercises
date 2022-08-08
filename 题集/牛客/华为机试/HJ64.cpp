// https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    string s;
    while (cin >> n >> s)
    {
        int index = 1;
        int up = 1, down = 4;

        for (char c : s)
        {
            if (c == 'U')
            {
                index--;
                if (index == 0)
                {
                    index = n;
                    up = index - 3;
                    down = n;
                }

                if (index < up)
                {
                    up = index;
                    down = index + 3;
                }
            }
            else
            {
                index++;

                if (index > n)
                {
                    index = 1;
                    up = 1;
                    down = 4;
                }

                if (down < index)
                {
                    up = index - 3;
                    down = index;
                }
            }
        }

        if (n < 5)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            for (int i = up; i <= down; i++)
            {
                cout << i << " ";
            }
        }

        cout << endl
             << index;
    }
    return 0;
}