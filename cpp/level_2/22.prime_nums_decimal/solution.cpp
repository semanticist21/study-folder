#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int solution(int n, int k)
{
    // to digit
    vector<char> k_digit;

    int at = 0;
    int c = n;

    while (c)
    {
        int q = c / k;
        int r = c % k;

        c = q;
        k_digit.emplace_back(r + '0');
    }

    reverse(k_digit.begin(), k_digit.end());

    string str(k_digit.begin(), k_digit.end());

    istringstream iss(str);
    string buff;
    vector<string> uniques;

    while (getline(iss, buff, '0'))
    {
        if (buff.size())
        {
            cout << buff << endl;
            uniques.emplace_back(buff);
        }
    }

    vector<long long> nums;
    for (const string str : uniques)
    {
        nums.emplace_back(stol(str));
    }

    int answer = 0;

    for (const long long num : nums)
    {
        if(num == 1) continue;
        

        int limit = sqrt(num);
        int start = 2;

        bool has = false;

        while (start <= limit)
        {
            if (num % start == 0)
            {
                has = true;
                break;
            }
            start++;
        }

        if(has) continue;
        else answer++;
    }

    return answer;
}

int main()
{
    int ans = solution(437674, 3);
    cout << ans << endl;
    return 0;
}