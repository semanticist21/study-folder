#include <bits/stdc++.h>
#include <vector>

using namespace std;

auto comp = [&](int a, int b)
{
  return a > b;
};

int solution(vector<int> A, vector<int> B)
{
  sort(A.begin(), A.end(), greater<>());
  sort(B.begin(), B.end(), less<>());

  int rs = 0;

  for (int i = 0; i < A.size(); i++)
    rs += A[i] * B[i];

  return rs;
}

int main()
{
  return 0;
}