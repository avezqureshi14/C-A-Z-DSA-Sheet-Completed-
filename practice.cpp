#include <iostream>

bool isPowerOf(int num, int base)
{
    while (num > 1 && num % base == 0)
    {
        num /= base;
    }

    return num == 1;
}

int main()
{
    int givenNumber = 3;
    int particularNumber = 16;

    if (isPowerOf(38416, 14))
    {
        std::cout << givenNumber << " is a power of " << particularNumber << std::endl;
    }
    else
    {
        std::cout << givenNumber << " is not a power of " << particularNumber << std::endl;
    }

    return 0;
}
