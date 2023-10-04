#include <cmath>
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
  int turns = 0;

  while (a != b)
  {
    a = (a + 1) >> 1;
    b = (b + 1) >> 1;
    ++turns;
  }

  return turns;
}

int solution_(int n, int a, int b)
{
  a--;
  b--;

  int answer = 0;

  while (a != b)
  {
    a = a / 2;
    b = b / 2;
    answer++;
  }
}

int main()
{
  int rs = solution(8, 4, 7);
  cout << rs << endl;
  return 0;
}