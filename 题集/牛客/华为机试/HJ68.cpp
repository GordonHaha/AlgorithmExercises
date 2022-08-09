// https://www.nowcoder.com/practice/8e400fd9905747e4acc2aeed7240978b
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    string name;
    int score;
    Student(string n, int s) : name(n), score(s){};
};

bool cmp0(const Student &a, const Student &b)
{
    return a.score > b.score;
}

bool cmp1(const Student &a, const Student &b)
{
    return a.score < b.score;
}

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        vector<Student> st;
        string name;
        int score;
        for (int i = 0; i < n; i++)
        {
            cin >> name >> score;
            Student temp = Student(name, score);
            st.push_back(temp);
        }

        if (k == 0)
        {
            stable_sort(st.begin(), st.end(), cmp0);
        }
        else
        {
            stable_sort(st.begin(), st.end(), cmp1);
        }
        for (int i = 0; i < n; i++)
        {
            cout << st[i].name << " " << st[i].score << endl;
        }
    }
    return 0;
}