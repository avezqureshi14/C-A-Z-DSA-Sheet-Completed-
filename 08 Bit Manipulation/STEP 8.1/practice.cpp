#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string decimalToBinary(int decimal)
{
    if (decimal == 0)
    {
        return "0";
    }

    string binary = "";
    while (decimal > 0)
    {
        int remainder = decimal % 2;
        cout << decimal << " " << remainder << endl;
        binary += to_string(remainder);
        decimal = decimal / 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int binaryToDecimal(string binary)
{
    int decimal = 0;
    int power = 1;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal = decimal + power;
        }
        power = power * 2;
    }
    return decimal;
}

int main()
{
    cout << 0 - '0';

    return 0;
}