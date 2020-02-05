/*
Max Sum
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 344680    Accepted Submission(s): 81946


Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence.
For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.


Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases.
Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).


Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case.
The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence.
 If there are more than one result, output the first one. Output a blank line between two cases.
*/
#include<iostream>
using namespace std;
struct Dp{          //Dynamic programming
    int sum;        //Sum records the maximum sum of the sub-sequence which is end of this note
    int begin;      //Begin records the begin of this sub-sequence
};
int a[100005];
Dp dp[100005];      //dp[0]=a[0]; dp[i]=max(dp[i-1]+dp[i],a[i]);
int main()
{
    int T;
    cin>>T;
    for(int c = 1;c<T+1;c++)
    {
        int N;
        cin>>N;
        //input
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        //init
        dp[0].sum = a[0];
        dp[0].begin = 1;
        //derivation
        for(int i=1;i<N;i++)
        {
            if(dp[i-1].sum+a[i]>=a[i])
            {
                dp[i].sum=dp[i-1].sum+a[i];
                dp[i].begin=dp[i-1].begin;
            }
            else
            {
                dp[i].sum=a[i];
                dp[i].begin=i+1;
            }
        }
        //search
        int maximum=dp[0].sum;
        int begin1=1,end1=1;
        for(int i=1;i<N;i++)
        {
            if(maximum<dp[i].sum)
            {
                maximum = dp[i].sum;
                end1=i+1;
                begin1=dp[i].begin;
            }
        }
        //output
        cout<<"Case "<<c<<":"<<endl<<maximum<<" "<<begin1<<" "<<end1<<endl;
        if(c!=T)cout<<endl;
    }
    return 0;
}
