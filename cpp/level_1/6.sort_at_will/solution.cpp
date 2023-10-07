#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
    auto sorter = [n](string a, string b)
    {
        return a[n] == b[n] ? a < b : a[n] < b[n];
    };

    sort(strings.begin(), strings.end(), sorter);

    return strings;
}

int main()
{
    vector<string> item = {"sun", "bed", "car"};
    int n = 1;

    auto rs = solution(item, n);
    cout << rs[2] << endl;

    return 0;
}