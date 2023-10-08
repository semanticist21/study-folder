#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr1[1] | arr2[i];
        string ans = "";

        for (int j = 0; j < n; j++)
        {
            if (arr1[i] % 2 == 0)
                ans = " " + ans;
            else
                ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
}

int main()
{
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};

    auto rs = solution(5, arr1, arr2);

    for (const string &str : rs)
        cout << str << endl;
    return 0;
}