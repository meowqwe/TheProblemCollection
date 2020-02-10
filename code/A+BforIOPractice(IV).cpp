/*
A+B for Input-Output Practice (IV)
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 161304    Accepted Submission(s): 83901


Problem Description
Your task is to Calculate the sum of some integers.


Input
Input contains multiple test cases.
Each test case contains a integer N, and then N integers follow in the same line.
A test case starting with 0 terminates the input and this test case is not to be processed.


Output
For each group of input integers you should output their sum in one line,
and with one line of output for each line in input.
*/
#include <iostream>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        if(!N) break;
        int sum=0, A;
        //cumulative
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
