#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

void do_sum(vector<int> nums, vector<int> cur, vector<int> &answers)
{
    if (cur.size() == 3)
    {
        int total = 0;
        for (const int &c : cur)
            total += c;
        answers.push_back(total);
        return;
    }

    if (nums.size() + cur.size() < 3)
        return;

    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> new_c(cur);
        vector<int> new_v(nums);

        new_c.emplace_back(nums[i]);
        new_v.erase(new_v.begin(), new_v.begin() + i + 1);
        do_sum(new_v, new_c, answers);
    }
}

int solution(vector<int> nums)
{
    sort(nums.rbegin(), nums.rend());
    int max = nums[0] + nums[1] + nums[2];

    unordered_set<int> not_primes;

    for (int i = 2; i < max; i++)
        for (int j = 2; i * j <= max; j++)
            not_primes.insert(i * j);

    vector<int> cur;
    vector<int> answers;
    do_sum(nums, cur, answers);

    int answer = 0;
    for (const int &sum : answers)
    {
        if (not_primes.find(sum) == not_primes.end())
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> b = {1, 2, 7, 6, 4};
    int rs = solution(b);
    cout << rs << endl;

    return 0;
}