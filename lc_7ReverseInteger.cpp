//Medium level leetcode asked in google

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int digit;
    int x = 1345;
    int revnum = 0;
    while (x != 0)
    {
        digit = x % 10;
        if (revnum > INT_MAX / 10 || revnum < INT_MIN / 10)
            return 0;
        revnum = (revnum * 10) + digit;
        x = x / 10;
    }
    cout << revnum;
}
