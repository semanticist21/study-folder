#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  return 0;
}

int solution(int n)
{
  vector<int> ternary;

  while (n > 0)
  {
    ternary.push_back(n % 3);
    n /= 3;
  }

  int size = ternary.size();

  int result = 0;
  for (const int &i : ternary)
  {
    result += i * pow(3, --size);
  }

  return result;
}