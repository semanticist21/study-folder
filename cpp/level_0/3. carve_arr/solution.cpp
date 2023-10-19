#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query)
{
    for (int i = 0; i < query.size(); i++)
    {
        if (i & 1)
            arr = vector<int>(arr.begin() + query[i], arr.end());
        else
            arr.erase(arr.begin() + query[i] + 1, arr.end());
    }

    return arr;
}

int main()
{
    vector<int> a = {0, 1, 2, 3, 4, 5};
    vector<int> b = {4, 1, 2};

    auto rs = solution(a, b);
    cout << rs[0] << endl;

    return 0;
}