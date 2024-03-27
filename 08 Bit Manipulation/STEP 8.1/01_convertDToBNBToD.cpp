#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// when u divided it by 2 ,TC will be  is always log base 2n

// Function to convert decimal to binary
string decimalToBinary(int decimal)
{
    if (decimal == 0)
    {
        return "0";
    }

    string binary = "";
    while (decimal > 0)
    {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string &binary)
{
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main()
{
    string binary = "1000010";
    int decimal = 21;
    // cout<<"Binary to Decimal "<<binaryToDecimal(binary)<<endl;
    cout << "Decimal to Binary of " << decimal << " is " << decimalToBinary(decimal) << endl;

    return 0;
}