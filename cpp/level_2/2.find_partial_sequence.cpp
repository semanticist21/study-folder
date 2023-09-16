#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
  int start = 0;
  int end = sequence.size() - 1;

  auto f = find(sequence.begin(), sequence.end(), k);

  if (f != sequence.end())
  {
    int addr = f - sequence.begin();
    return {addr, addr};
  }

  while (true)
  {
    int v = 0;

    for (int i = start; i <= end; i++)
    {
      v += sequence[i];
    }

    if (v == k)
      break;

    int gap = v - k;

    if (gap == sequence[end])
    {
      --end;
      break;
    }
    else if (gap == sequence[start])
    {
      ++start;
      break;
    }

    if (gap > sequence[end])
      --end;
    else
      ++start;
  }

  return {start, end};
}

int main()
{
  auto result = solution({1, 1, 1, 2, 3, 4, 5}, 5);
  for (const int v : result)
  {
    cout << v << endl;
  }

  return 0;
}