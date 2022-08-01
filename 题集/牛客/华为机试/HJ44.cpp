// https://www.nowcoder.com/practice/78a1a4ebe8a34c93aac006c44f6bf8a1
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix(9, vector<int>(9));
bool find_ans;

bool check(int x, int y, int val)
{
    // 同行、列检查
    for (int i = 0; i < 9; i++)
    {
        if (matrix[x][i] == val || matrix[i][y] == val)
        {
            return false;
        }
    }

    // 九宫格检查
    int limit_x = x / 3 * 3 + 3;
    int limit_y = y / 3 * 3 + 3;
    for (int i = limit_x - 3; i < limit_x; i++)
    {
        for (int j = limit_y - 3; j < limit_y; j++)
        {
            if (matrix[i][j] == val)
            {
                return false;
            }
        }
    }
    return true;
}

void back_track(int x, int y)
{
    if (y == 9)
    {
        x++;
        y = 0;
    }

    if (x == 9 && y == 0)
    {
        find_ans = true;
        return;
    }

    if (matrix[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check(x, y, i))
            {
                matrix[x][y] = i;
                back_track(x, y + 1);
                if (find_ans)
                    return;
                matrix[x][y] = 0;
            }
        }
    }
    else
    {
        back_track(x, y + 1);
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> matrix[i][j];
        }
    }

    back_track(0, 0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}