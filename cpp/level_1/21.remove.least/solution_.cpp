#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int min = *min_element(arr.begin(), arr.end());
    int pos = find(arr.begin(), arr.end(), min) - arr.begin();

    arr.erase(arr.begin() + pos);
    return arr;
}

int main()
{
    vector<int> arr = {4, 3, 2, 1};
    auto rs = solution(arr);

    for (const int &i : rs)
        cout << i << endl;

    return 0;
}