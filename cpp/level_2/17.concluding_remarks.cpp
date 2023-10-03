#include <unordered_map>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
  unordered_map<string, bool> m;

  unordered_set<string> ms;

  ms.insert(words[0]).second;

  int stop = -1;

  char prev_end = words[0].back();
  m.insert(make_pair(words[0], true));

  for (int i = 1; i < words.size(); i++)
  {
    string word = words[i];

    if (prev_end != word.front())
    {
      stop = i;
      break;
    }

    if (m.find(word) != m.end())
    {
      stop = i;
      break;
    }

    m.insert(make_pair(word, true));
    prev_end = word.back();
  }

  if (stop == -1)
    return {0, 0};

  int loser = stop % n + 1;
  int turns = stop / n + 1;

  return {loser, turns};
}

int main()
{
  vector<string> a = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
  auto rs = solution(3, a);

  cout << rs[0] << " " << rs[1] << endl;

  return 0;
}