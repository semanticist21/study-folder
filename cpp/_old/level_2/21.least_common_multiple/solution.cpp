#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

int solution(vector<int> arr)
{
  unordered_set<int> m;

  for (const int &n : arr)
  {
    for (int i = 2; i <= n; i++)
      if (n % i == 0)
        m.insert(i);
  }

  unordered_map<int, int> m_;

  for (const int &n : m)
  {
    vector<int> d;

    for (int i = 2; i <= n; i++)
      if (n % i == 0)
        d.push_back(i);

    if (d.back() == pow(d.front(), d.size()))
    {
      m_[d.front()] = m_[d.front()] >= d.size() ? m_[d.front()] : d.size();
      continue;
    }

    if (d.size() == 1)
      m_[d.front()] = 1;
  }

  int answer = 1;
  for (const auto &pair : m_)
    answer *= pow(pair.first, pair.second);

  return answer;
}

int main()
{
  int rs = solution({2, 6, 8, 14});
  cout << rs << endl;
  return 0;
}