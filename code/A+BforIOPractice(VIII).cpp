/*
A+B for Input-Output Practice (VIII)
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 246198    Accepted Submission(s): 71516


Problem Description
Your task is to calculate the sum of some integers.


Input
Input contains an integer N in the first line, and then N lines follow.
Each line starts with a integer M, and then M integers follow in the same line.


Output
For each group of input integers you should output their sum in one line,
and you must note that there is a blank line between outputs.
*/
#include <iostream>
using namespace std;
int main()
{
    int N, M;
    cin>>N;
    while(N--)
    {
        cin>>M;
        //cumulative
        int sum=0, A;
        while(M--)
        {
            //input
            cin>>A;
            sum+=A;
        }
        //output
        cout<<sum<<endl;
        //format
        if(N) cout<<endl;
    }
    return 0;
}
