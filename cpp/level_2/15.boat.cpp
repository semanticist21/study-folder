#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
  sort(people.begin(), people.end());

  int i = 0;
  for (int j = people.size() - 1; i < j; j--)
    if (people[i] + people[j] <= limit)
      ++i;

  return people.size() - i;
}

int main()
{
  auto rs = solution({10, 20, 30}, 130);
  cout << rs << endl;

  return 0;
}
