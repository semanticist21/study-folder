#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
  int s = 0;
  int e = 0;

  int f_s = 0;
  int f_e = sequence.size();
  int size = sequence.size();

  int sum = sequence[0];
  while (true)
  {
    if (sum < k)
    {
      if (e < size - 1)
        sum += sequence[++e];
      else
        break;
    }

    if (sum > k)
      sum -= sequence[s++];

    if (sum == k)
    {
      if (e - s < f_e - f_s)
      {
        f_s = s;
        f_e = e;
      }

      sum -= sequence[s++];
    }
  }

  return {f_s, f_e};
}

int main()
{
  vector<int> result = solution({1, 2, 3, 4, 5}, 7);
  for (const int &i : result)
  {
    cout << i << endl;
  }

  return 0;
}