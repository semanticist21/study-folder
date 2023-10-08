#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(int a, int b)
{
    vector<int> d_31 = {1, 3, 5, 7, 8, 10, 12};
    vector<int> d_30 = {4, 6, 9, 11};
    vector<int> d_29 = {2};

    unordered_map<int, int> set;
    for (const int &i : d_31)
        set.insert(make_pair(i, 31));
    for (const int &i : d_30)
        set.insert(make_pair(i, 30));
    for (const int &i : d_29)
        set.insert(make_pair(i, 29));

    int cnt = 0;
    for (int i = 1; i < a; i++)
        cnt += set[i];

    cnt += b;

    int plus = cnt % 7;
    vector<string> days = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

    return days[plus];
}

int main()
{
    auto rs = solution(5, 24);
    cout << rs << endl;
    return 0;
}