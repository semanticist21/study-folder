#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int least = 0x7fffffff;

    for (const int &n : arr)
        if (n < least)
            least = n;

    auto find_ = [least](int &a)
    {
        return a == least;
    };
    arr.erase(remove_if(arr.begin(), arr.end(), find_));

    return arr.size() ? arr : vector<int>(1, -1);
}

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    auto rs = solution(arr);

    for (const int &i : rs)
        cout << i << endl;

    return 0;
}