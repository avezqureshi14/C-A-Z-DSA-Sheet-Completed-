#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//row and column is given, We have to tell the element at that place
//n = number of rows //r = columns {n-i+1}
int nCr(int n, int r){
    n = n-1;
    r = r-1;
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}
 

//this function will be generating pascal triangle row for the g//iven row 
vector<int>generateRow(int row){
    long long ans = 1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row-col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;    
}

//generate the triangle as per the given number of rows

vector<vector<int>> pascalTraingle(int n){
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;    
}

int main()
{
    for(auto i : pascalTraingle(5)){
        cout<<endl;
        for(auto j : i){
            cout<<j<<" ";
        }
    }

    cout<<endl;
    cout<<endl;
    cout<<nCr(4,2);
    return 0;
}