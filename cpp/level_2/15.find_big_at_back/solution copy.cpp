#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> unresolved;
    vector<int> answer(numbers.size(), -1);

    unresolved.emplace_back(0);
    int unresolved_min = numbers[0];

    for (int i = 1; i < numbers.size(); i++)
    {
        int cur = numbers[i];

        if (cur > unresolved_min)
        {
            vector<int> new_vec;
            unresolved_min = 0x7fffffff;

            for (int j = 0; j < unresolved.size(); j++)
            {
                if (cur > numbers[unresolved[j]])
                {
                    answer[unresolved[j]] = cur;
                }
                else
                {
                    if (numbers[unresolved[j]] < unresolved_min)
                        unresolved_min = numbers[unresolved[j]];

                    new_vec.emplace_back(unresolved[j]);
                }
            }

            unresolved = new_vec;
        }

        if (cur < unresolved_min)
            unresolved_min = cur;

        unresolved.emplace_back(i);
    }

    return answer;
}

int main()
{
    return 0;
}