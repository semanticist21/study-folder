#include <bits/stdc++.h>

// 유클리드 호제법
int gcd(int x, int y) { return x % y == 0 ? y : gcd(x, x % y); }
int lcm(int x, int y) { return x * y / gcd(x, y); }

int solution(vector<int> arr)
{
  int answer = arr[0];
  for (int i = 1; i < arr.size(); i++)
    answer = lcm(answer, arr[i]);

  return answer;
}

int main()
{
  return 0;
}