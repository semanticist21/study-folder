#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int solution(int x, int y, int n)
{
    int cur = x;
    int cnt = 0;

    while(cur < y){
        if(y%(cur*3) == 0 && cur+n < cur * 3) cur*=3;
        else if(y%(cur*2) == 0 && cur+n <= cur * 2) cur*= 2;
        else cur += n;

        cnt++;
    }

    if(cur != y) return -1;
    else return cnt;
}

int main()
{
    return 0;
}