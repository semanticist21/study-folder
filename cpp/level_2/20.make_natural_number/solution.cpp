#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void iter_operation(int cur, int op, int &target, int &adder, int &min)
{
    if (cur >= target)
    {
        if (cur == target && op < min)
            min = op;
        return;
    }

    iter_operation(cur + adder, ++op, target, adder, min);
    iter_operation(cur * 2, op, target, adder, min);
    iter_operation(cur * 3, op, target, adder, min);
}

int solution(int x, int y, int n)
{
    int max_val = numeric_limits<int>::max();
    int min = max_val;
    iter_operation(x, 0, y, n, min);

    return min == max_val ? -1 : min;
}

int main(){
    return 0;
}