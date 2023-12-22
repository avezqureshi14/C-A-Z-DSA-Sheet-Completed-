#include <iostream>
#include <bits/stdc++.h>
typedef pair<int,pair<int,int>>ppi; 
using namespace std;
int main()
{
    // this is max heap
    priority_queue<int> maxHeap;
    maxHeap.push(5);
    maxHeap.push(4);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(1);
    cout << maxHeap.top();

    // this is min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(4);
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(1);
    cout << minHeap.top();
    return 0;
}