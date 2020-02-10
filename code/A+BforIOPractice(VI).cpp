/*
A+B for Input-Output Practice (VI)
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 111456    Accepted Submission(s): 73068


Problem Description
Your task is to calculate the sum of some integers.


Input
Input contains multiple test cases, and one case one line.
Each case starts with an integer N, and then N integers follow in the same line.


Output
For each test case you should output the sum of N integers in one line,
and with one line of output for each line in input.
*/
#include <iostream>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        //cumulative
        int sum=0, A;
        while(N--)
        {
            //input
            cin>>A;
            sum+=A;
        }
        //output
        cout<<sum<<endl;
    }
    return 0;
}
