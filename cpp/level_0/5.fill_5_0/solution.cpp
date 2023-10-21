#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int l, int r)
{
    int max = to_string(r).size();
    vector<int> nums;
    nums.reserve(max * 2);

    for (int i = 0; i <= max; i++)
    {
        int new_num = round(pow(10, i));

        for (const int &num : nums)
            nums.emplace_back(new_num + num);

        nums.emplace_back(new_num);
    }

    vector<int> answer;

    for (int &num : nums)
        if (num * 5 >= l && num * 5 <= r)
            answer.emplace_back(num * 5);

    sort(answer.begin(), answer.end());

    if (answer.empty())
        answer.emplace_back(-1);

    return answer;
}

int main()
{
    auto rs = solution(555, 555);
    for (const auto &i : rs)
        cout << i << endl;

    cout << endl
         << endl
         << rs.size() << endl;
    return 0;
}