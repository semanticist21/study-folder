#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> marked(numbers.size(), -1);

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        int t = numbers[i];
        int s = i;
        while (true)
        {
            if (s == numbers.size() - 1)
                break;

            if (numbers[++s] > t)
            {
                marked[i] = numbers[s];
                break;
            }
        }
    }
}

int main()
{
    return 0;
}