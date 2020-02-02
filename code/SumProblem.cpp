/*
*Sum Problem
Input: The input will consist of a series of integers n, one integer per line.
Output:For each case, output SUM(n) in one line, followed by a blank line. You may assume the result will be in the range of 32-bit signed integer.
*/
#include<iostream>
using namespace std;

int main()
{
    long n;
    while(cin>>n)
    {
        int temp = n;
        int sum = 0;
        while(temp)
        {
            sum += temp;
            temp--;
        }
        cout<<sum<<endl;
        cout<<endl;
    }
}
