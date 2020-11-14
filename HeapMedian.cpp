#include "MedianHeap.h"
#include <iostream>
#include <queue>
#include <vector>
#include "testing/SimpleTest.h"


using namespace std;
// Construcctor
MedianHeap::MedianHeap() {
    _median = 0;
    _MaxHeap = {};
    _MinHeap = {};
}
// Given two integars, returns average
int MedianHeap::average(int one, int two) {
    int average = (one + two) / 2;
    return average;

}
// this code inspired by median integar problems on LeetCode and GeeksForGeeks
// This function, given a stream of integars, uses a max heap and a min heap to arrange the numbers such that the
// median can be returned at any given point. This simulation models the Median Voter Theorem, which states that the swing vote
// will always be the ideological median. 

void MedianHeap::insertVoter(int voter){
    if (_MaxHeap.size() > _MinHeap.size()){ // if there are more elements in max heap than min,

        if (voter < _median){ // if curr elem fits into max heap, we will have an inbalance
            int value = _MaxHeap.top(); // get top num
            _MaxHeap.pop(); // remove top num
            _MinHeap.push(value); // send top num to Min Heap
            _MaxHeap.push(voter); // add voter to Max Heap
            // Extension: the above can be done with several helper functions
        }
        else {
            _MinHeap.push(voter); // curr elem fits into min heap
        }
        _median = average(_MaxHeap.top(), _MinHeap.top()); // heaps are balanced, get average (new median)
    }
    else if (_MaxHeap.size() == _MinHeap.size()){
        if (voter < _median){
            _MaxHeap.push(voter);
            _median = _MaxHeap.top();
        }else{
            _MinHeap.push(voter);
            _median = _MinHeap.top();
        // if they are the same size, the logic is more simple.
        }
    }else{
        if (voter < _median) {
            _MaxHeap.push(voter);
        }else {
            int value = _MinHeap.top();
            _MinHeap.pop();
            _MaxHeap.push(value);
            _MinHeap.push(voter);
        }
        _median = average(_MaxHeap.top(), _MinHeap.top());
    }

}
// returns median. 
int MedianHeap::getMedian(){
    return _median;
}

STUDENT_TEST("Testing getting median from a stream, with multiple votes"){
    MedianHeap mh;
    vector<int> vec = {1, 30, 40, 2, 15, 70, 5};
    for (int elem : vec){
        mh.insertVoter(elem);
        cout << mh.getMedian() << endl;
    }
}
STUDENT_TEST("Testing getting median from a stream, with multuple votes"){
    MedianHeap mh;
    vector<int> vec = {17};
    for (int elem : vec){
        mh.insertVoter(elem);
        cout << mh.getMedian() << endl;
    }
}

STUDENT_TEST("Testing getting median from a stream, compare with Vector version"){
    MedianHeap mh;
    vector<int> vec = {1, 30, 40, 2, 15, 70, 5};
    for (int elem : vec){
        mh.insertVoter(elem);
        cout << mh.getMedian() << endl;
    }
}
STUDENT_TEST("Testing getting median from a stream, with no voters"){
    MedianHeap mh;
    vector<int> vec = {};
    for (int elem : vec){
        mh.insertVoter(elem);
        cout << mh.getMedian() << endl;
    }
}

