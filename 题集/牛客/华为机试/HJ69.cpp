// https://www.nowcoder.com/practice/ebe941260f8c4210aa8c17e99cbc663b
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int x, y, z;
    while (cin >> x >> y >> z)
    {
        vector<vector<int>> A(x, vector<int>(y));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cin >> A[i][j];
            }
        }
        vector<vector<int>> B(y, vector<int>(z));
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < z; j++)
            {
                cin >> B[i][j];
            }
        }
        vector<vector<int>> C(x, vector<int>(z));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < z; j++)
            {
                for (int k = 0; k < y; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < z; j++)
            {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}