#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements)
{
    unordered_set<int> sums;
    for (int i = 0; i < elements.size(); i++)
    {
        for (int j = 0; j < elements.size(); j++)
        {
            int start = i;
            int end = j;

            int total = 0;
            for (int k = 0; k < end; k++)
            {
                if (i + k >= elements.size())
                    total += elements[i + k - elements.size()];
                else
                    total += elements[i + k];
            }

            sums.insert(total);
        }
    }

    return sums.size();
}

int main()
{
    vector<int> input = {7, 9, 1, 1, 4};
    auto rs = solution(input);
    cout << rs << endl;

    return 0;
}