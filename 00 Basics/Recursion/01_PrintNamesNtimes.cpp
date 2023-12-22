#include <iostream>
using namespace std;
int n = 0; 
void printNamesNtimes(){
    if (n == 10)
    {
    return;
    }
    cout<<"Avez";
    n++;
    printNamesNtimes();
    
}
int main()
{
    printNamesNtimes();
    return 0;
}


