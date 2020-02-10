/*
A+B for Input-Output Practice (III)
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 171250    Accepted Submission(s): 90167


Problem Description
Your task is to Calculate a + b.


Input
Input contains multiple test cases. Each test case contains a pair of integers a and b,
one pair of integers per line. A test case containing 0 0 terminates the input and this test case is not to be processed.


Output
For each pair of input integers a and b you should output the sum of a and b in one line,
and with one line of output for each line in input.
*/
#include <iostream>
using namespace std;
int main()
{
    int A, B;
    while(true)
    {
        //input
        cin>>A>>B;
        if(!(A||B)) break;//break conditions
        //output
        cout<<A+B<<endl;
    }
    return 0;
}
