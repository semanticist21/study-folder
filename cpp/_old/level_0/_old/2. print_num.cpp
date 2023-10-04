#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int a;
  int b;
  cin >> a >> b;
  string a_str = "a = " + std::to_string(a);
  string b_str = "b = " + std::to_string(b);

  cout << a_str << '\n' << b_str << endl;

  return 10;
}