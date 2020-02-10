/*
A+B for Input-Output Practice (II)
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 157829    Accepted Submission(s): 99295


Problem Description
Your task is to Calculate a + b.


Input
Input contains an integer N in the first line, and then N lines follow.
Each line consists of a pair of integers a and b, separated by a space, one pair of integers per line.


Output
For each pair of input integers a and b you should output the sum of a and b in one line,
and with one line of output for each line in input.

*/
#include <iostream>
using namespace std;
int main()
{
    int N;
    //lines
    cin>>N;
    while(N--)
    {
        int A, B;
        cin>>A>>B;
        //output
        cout<<A+B<<endl;
    }
    return 0;
}
