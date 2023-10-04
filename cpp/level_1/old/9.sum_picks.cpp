#include <bits/stdc++.h>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers)
{
  set<int> st;

  for (int i = 0; i < numbers.size(); i++)
  {
    for (int j = i + 1; j < numbers.size(); j++)
    {
      st.insert(numbers[i] + numbers[j]);
    }
  }

  return vector<int>(st.begin(), st.end());
}

int main()
{
  return 0;
}