#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> stack;
    vector<int> stock(prices.size(), 0);

    for (int i = 0; i < prices.size(); i++)
    {
        int cur = prices[i];

        for (int &idx : stack)
        {
            if (idx == -1)
                continue;
            int data = prices[idx];
            if (cur < data)
            {
                stock[idx] = i - idx;
                idx = -1;
            }
        }

        vector<int> new_vec;
        new_vec.reserve(stack.size());

        for (const int &idx : stack)
            if (idx != -1)
                new_vec.emplace_back(idx);

        stack = new_vec;

        stack.emplace_back(i);
    }

    for (const int &idx : stack)
        if (idx != -1)
            stock[idx] = stock.size() - idx - 1;

    return stock;
}

int main()
{
    return 0;
}