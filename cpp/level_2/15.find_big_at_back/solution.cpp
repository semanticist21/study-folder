#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    stack<int> unresolved;

    for (int i = 0; i < numbers.size(); i++)
    {
        int cur = numbers[i];

        while (!unresolved.empty() && numbers[unresolved.top()] < cur)
        {
            answer[unresolved.top()] = cur;
            unresolved.pop();
        }

        unresolved.push(i);
    }

    return answer;
}

int main()
{
    return 0;
}