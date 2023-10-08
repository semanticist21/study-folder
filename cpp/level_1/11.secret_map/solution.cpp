#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<vector<char>> map;
    map.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int m1 = arr1[i];
        int m2 = arr2[i];

        string b1 = bitset<32>(m1).to_string();
        string b2 = bitset<32>(m2).to_string();

        b1.erase(b1.begin(), b1.end() - n);
        b2.erase(b2.begin(), b2.end() - n);

        vector<char> chars;
        chars.reserve(n);

        for (int i = 0; i < n; i++)
            if (b1[i] == '1' || b2[i] == '1')
                chars.emplace_back('#');
            else
                chars.emplace_back(' ');

        map.emplace_back(chars);
    }

    vector<string> answer;
    for (const vector<char> c : map)
        answer.emplace_back(string(c.begin(), c.end()));

    return answer;
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