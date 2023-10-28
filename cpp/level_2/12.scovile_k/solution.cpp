#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void push(vector<int> &heap, int input)
{
    heap.emplace_back(input);

    int self = heap.size() - 1;
    int parent = (self - 1) / 2;

    while (self > 0 && heap[self] < heap[parent])
    {
        swap(heap[parent], heap[self]);
        self = parent;
        parent = (self - 1) / 2;
    }
}

int pop(vector<int> &heap)
{
    if (heap.size() == 1)
    {
        int result = heap.back();
        heap.pop_back();
        return result;
    }

    swap(heap.front(), heap.back());

    int top = heap.back();
    heap.pop_back();

    int parent = 0;
    int child = 1;

    if (heap.size() > 2 && heap[2] < heap[1])
        child += 1;

    while (child <= heap.size() - 1 && heap[child] < heap[parent])
    {
        swap(heap[parent], heap[child]);

        parent = child;
        child = 2 * parent + 1;

        if (heap.size() - 2 > child && heap[child + 1] < heap[child])
            child += 1;
    }

    return top;
}

int solution(vector<int> scoville, int K)
{
    vector<int> heap;
    heap.reserve(scoville.size());

    for (const int &s : scoville)
        push(heap, s);

    int iter = 0;

    while (heap.front() < K)
    {
        if (heap.size() < 2)
        {
            iter = -1;
            break;
        }

        int least = pop(heap);
        int next_least = pop(heap);

        int combined = least + next_least * 2;

        push(heap, combined);
        iter++;
    }

    return iter;
}

int main()
{
    vector<int> test = {1, 2, 3, 9, 11, 12};
    auto rs = solution(test, 7);

    cout << rs << endl;
    return 0;
}