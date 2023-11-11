#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void iter_operation(int cur, int op, int &target, int &adder, vector<int> &ops)
{
    if (cur >= target)
    {
        if (cur == target)
            ops.emplace_back(op);
        return;
    }

    iter_operation(cur + adder, ++op, target, adder, ops);
    iter_operation(cur * 2, op, target, adder, ops);
    iter_operation(cur * 3, op, target, adder, ops);
}

int solution(int x, int y, int n)
{
    vector<int> ops;
    iter_operation(x, 0, y, n, ops);

    return ops.empty() ? -1 : *min_element(ops.begin(), ops.end());
}

int main()
{
    return 0;
}