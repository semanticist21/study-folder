#include <bits/stdc++.h>

using namespace std;

string solution(string s)
{
  vector<string> words;

  string token;
  char delimiter = ' ';
  istringstream stream(s);

  while (getline(stream, token, delimiter))
  {
    words.push_back(token);
  }

  vector<int> nums;
  nums.reserve(words.size());

  for (const string &word : words)
  {
    nums.push_back(stoi(word));
  }

  int min = *min_element(nums.begin(), nums.end());
  int max = *max_element(nums.begin(), nums.end());

  ostringstream os;

  os << min << " " << max << endl;

  return os.str();
}

int main()
{
  string val = solution("1 2 3 4");

  cout << val << endl;
  return 0;
}