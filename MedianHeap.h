
#pragma once
#include <queue>
#include <vector>
using namespace std;


class MedianHeap {

public:
    MedianHeap();
    void insertVoter(int voter);
    int getMedian();
    int average(int one, int two);


private:

    int _median;
    priority_queue<int> _MaxHeap;
    priority_queue<int, vector<int>, greater<int>> _MinHeap;
};

