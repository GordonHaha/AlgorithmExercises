// https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
void back_track(vector<vector<int>> matrix, vector<vector<int>> &track, int x, int y)
{

    if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] == 1)
    {
        return;
    }

    matrix[x][y] = 1;
    track.push_back({x, y});
    if (x == matrix.size() - 1 && y == matrix[0].size() - 1)
    {
        res.assign(track.begin(), track.end());
    }
    back_track(matrix, track, x - 1, y);
    back_track(matrix, track, x + 1, y);
    back_track(matrix, track, x, y - 1);
    back_track(matrix, track, x, y + 1);
    matrix[x][y] = 0;
    track.pop_back();
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> track;
    back_track(matrix, track, 0, 0);
    for (vector<int> vec : res)
    {
        cout << "(" << vec[0] << "," << vec[1] << ")" << endl;
    }
    return 0;
}