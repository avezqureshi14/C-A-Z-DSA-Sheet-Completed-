#include <iostream>
using namespace std;
int count = 1;
void oneToN(){
    if (count == 10)
    {
        return;
    }

    cout<<count<<" ";
    count++;
    oneToN();
    
}
int main()
{
    oneToN();
    return 0;
}