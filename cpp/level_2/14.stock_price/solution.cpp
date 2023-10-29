#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int cur_top = 0;
    vector<int> answer(prices.size(), 0);

    for (int i = 0; i < prices.size(); i++)
    {
        int cur = prices[i];
        if (cur >= cur_top)
        {
            cur_top = cur;
            continue;
        }

        int gap = 1;
        int pos = i;
        while (cur < cur_top)
        {
            answer[pos - gap] = gap;

            if (pos - gap - 1 < 0)
                break;

            cur_top = prices[pos - gap - 1];
            gap++;
        }
    }

    for (int i = 0; i < answer.size(); i++)
        if (answer[i] == 0)
            answer[i] = answer.size() - 1 - i;

    return answer;
}

int main()
{
    return 0;
}