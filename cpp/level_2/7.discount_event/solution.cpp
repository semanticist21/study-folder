#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    unordered_map<string, int> wants;
    for (int i = 0; i < want.size(); i++)
        wants[want[i]] += number[i];

    int int_at = 0;

    for (int i = 0; i < discount.size() - 9; i++)
    {
        unordered_map<string, int> wants_copy(wants);

        for (int j = i; j < 10 + i; j++)
            wants_copy[discount[j]] -= 1;

        bool flag = false;

        for (const pair<string, int> &p : wants_copy)
            if (p.second > 0)
                flag = true;

        if (!flag)
            int_at++;
    }

    return int_at;
}

int main()
{
    vector<string> a = {"banana", "apple", "rice", "pork", "pot"};
    vector<int> nums = {3, 2, 2, 2, 1};
    vector<string> disks = {"chicken",
                            "apple",
                            "apple",
                            "banana",
                            "rice",
                            "apple",
                            "pork",
                            "banana",
                            "pork",
                            "rice",
                            "pot",
                            "banana",
                            "apple",
                            "banana"};

    auto rs = solution(a, nums, disks);
    cout << rs << endl;

    return 0;
}