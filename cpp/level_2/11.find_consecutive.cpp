#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n)
{
  int s = 1;
  int answer = 0;

  while (s <= n / 2 + 1)
  {
    int acc = 0;
    for (int i = s; i < n; i++)
    {
      acc += i;

      if (acc == n)
      {
        answer++;
        break;
      }
      else if (acc > n)
        break;
    }
    s++;
  }

  return answer + 1;
}

int main()
{
  auto r = solution(15);
  cout << r << endl;
  return 0;
}