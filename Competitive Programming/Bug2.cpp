#include <bits/stdc++.h>
using namespace std;
long long maximumNum(long A,long  B,long  C)
{
    long num = 2;
    if (C - C % A + B < C+A) {

        num = C - C % A + B;
    }
    else {
        num = C - C % A - (A - B);
    }
    return num;
}
int main()
{
    long  A = 10;
    long  B = 5;
    long  C = 15;

    cout << maximumNum(A, B, C);

    return 0;
}
