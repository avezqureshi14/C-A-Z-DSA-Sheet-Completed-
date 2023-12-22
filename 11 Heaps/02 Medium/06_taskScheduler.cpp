#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int leastInterval(vector<char>&tasks, int n){
    unordered_map<char,int>counts;
    for(char t : tasks){
        counts[t]++;
    }
    priority_queue<int>maxHeap;
    for(auto i : counts){
        maxHeap.push(i.second);
    }
    int result = 0;
    while (!maxHeap.empty())
    {
        int time = 0;
        vector<int>tmp;
        for (int i = 0; i < n + 1; i++)
        {
            if (!maxHeap.empty())
            {
                tmp.push_back(maxHeap.top()-1);
                maxHeap.pop();
                time++;
            }
        }
        for(auto i : tmp){
            if (i)
            {
                maxHeap.push(i);
            }
        }
        if (!maxHeap.empty())
        {
            result = result + n + 1;
        }
        else{
            result = result + time;
        }                
    }
    return result;
}
int main()
{
    
    return 0;
}