#include <iostream>

using namespace std;

int solution(int price)
{
  if (price >= 500000)
    return price * 0.8;
  else if (price >= 300000)
    return price * 0.90;
  else if (price >= 100000)
    return price * 0.95;
  else
    return price;
}

int main()
{
  return 0;
}